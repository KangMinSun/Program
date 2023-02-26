#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node Node;
typedef struct node{
    float data;   // ���� ���ÿ� 
    //char operator[1];  // ��ȣ ���ÿ�
    //struct node* link;
    Node* link;
} num_Node;

typedef struct node2{    
    Node* top;
    int count;
} usr_Stack;

//�Լ� ����
void push(usr_Stack* stk, float data); // ������ ���� ���� data���� ���� ��� ����
float pop(usr_Stack* stk); //������ ���� �� ��带 �����ϰ� �� data���� ��ȯ
int isStackEmpty(usr_Stack* stk); //������ ��������� 1(True)��ȯ, �ƴϸ� 0(False)��ȯ
void clear(usr_Stack* stk); // ������ ��� ��� ����(���� �� ��� �ص� �ǰ� ���ص� ��)

char* postfix(char* str, char* str2); // ���� ǥ����(���ڿ�)�� �Է¹޾� ���� ǥ����(���ڿ�)�� ��ȯ �� ��ȯ�ϴ� �Լ�
float calculate(char* str); //���� ǥ����(���ڿ�)�� �Է¹޾� ������ ���� ����� �� �����(�Ǽ�)�� ��ȯ�ϴ� �Լ� 
float operation(float op1, float op2); //�ǿ����� �� ���� �����ڸ� �Է¹޾Ƽ� �׿� �°� ��Ģ���� ���� �� ����� ��ȯ
int OperationPriority(float op); //������ �켱���� ������

int main() {

    char str[30]; // �ԷµǴ� ������ ���� ���� �迭
    char str2[30]; // ���� ǥ�������� ��ȯ�� ������ ���� ���� �迭
    int len1; // ���� ǥ���� ���ڿ��� ����
    int len2; // ���� ǥ���� ���ڿ��� ����
    float result; // ��� �����
    
    scanf("%s", str);
    //gets(str);
    //char str[30] = ['1', '+', '2', '*', '3', '+', '4', '/', '5', '\0'];
    
    postfix(str, str2);
    printf("main() %s\n", str2);
    result = calculate(str2);
    printf("����� : %f", result);

    //���� ���� Ȯ�� �ڵ�
/*
    int input = 1;
    usr_Stack stack1;
    stack1.top = 0;
    stack1.count = 0;

    while (input) {
        scanf("%d\n", &input);
        push(&stack1, (float)input);
    }
    num_Node *itr;
    for (itr = stack1.top; itr != NULL; itr = itr->link) {
        printf("%f\t", itr->data);
    }
    printf("\n stack size : %d\n", stack1.count);

    int i = 0;
    float num = 0;
    int count = stack1.count;
    for (i = 0; i < count; i++) {
        num = pop(&stack1);
        printf("%f\n", num);

        for (itr = stack1.top; itr != NULL; itr = itr->link) {
            printf("%d ", (int)itr->data);
        }
        printf("\n");
        printf("\n stack size : %d\n", stack1.count);

    }
    printf("\n stack size : %d\n", stack1.count);
*/


}

void push(usr_Stack* stk, float num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->link = stk->top;
    stk->top = newNode;
    stk->count++;
}

float pop(usr_Stack* stk) {
    if (isStackEmpty(stk)) {
        printf("stack is empty");
        exit(-1);
    }
    Node* rnode = stk->top;
    float rdata = rnode->data;
    stk->top = stk->top->link;
    free(rnode);

    stk->count--;
    return rdata;
}

int isStackEmpty(usr_Stack* stk) {
    if (stk->top == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

char* postfix(char* str, char* str2) {
    usr_Stack stack;
    stack.count = 0;
    stack.top = NULL;
    int strLen = strlen(str);
    int i, j = 0;    

    for (i = 0; i < strLen; i++) {
        if (isdigit(str[i])) {
            str2[j] = str[i];
            j++;
        }
        else {
            if (isStackEmpty(&stack)) {
                push(&stack, str[i]);
            }

            else if ((float)operation(stack.top->data, str[i]) == -1) {
                push(&stack, str[i]);
            }

            else if ((float)operation(stack.top->data, str[i]) == 1 || 0) {
                str2[j++] = pop(&stack);
                while ((float)operation(stack.top->data, str[i]) != -1) {
                    while (!isStackEmpty(&stack)) {
                        str2[j++] = pop(&stack);
                    }
                    if (isStackEmpty(&stack) == 1)
                        break;
                }
                push(&stack, str[i]);
            }

            else {
                switch (str[i]) {
                case '(':
                    push(&stack, str[i]);
                    break;

                case ')':
                    while (stack.top != '(') {
                        str2[j++] = pop(&stack);
                    }
                    pop(&stack);
                }
            }
        }
        
    }
    while (!isStackEmpty(&stack)) {
        str2[j++] = pop(&stack);
    }
    str2[j] = '\0';

    printf("postfix() %s\n", str2);
}

float calculate(char* str) {
    usr_Stack stack;
    int strLen = strlen(str);
    int i = 0;
    char tmp;
    float op1, op2;
    
    for (i = 0; i < strLen; i++) {
        tmp = str[i];
        if (isdigit(tmp)) {
            push(&stack, (float)tmp - 48);
        }
        else {
            op2 = pop(&stack);
            op1 = pop(&stack);

            switch (tmp) {
            case '+':
                push(&stack, op1 + op2);
                break;
            case '-':
                push(&stack, op1 - op2);
                break;
            case '*':
                push(&stack, op1 * op2);
                break;
            case '/':
                push(&stack, op1 / op2);
                break;
            }
        }
    }
    return pop(&stack);
}

int OperationPriority(float op) {
    switch ((int)op) {
    case 42:
    case 47:
        return 3;
    case 43:
    case 45:
        return 2;
    case 40:
        return 1;
    default:
        return -1;
    }
}

float operation(float op1, float op2) {
    int op1pr = OperationPriority(op1);
    int op2pr = OperationPriority(op2);

    if (op1pr > op2pr) {
        return 1;
    }
    else if (op1pr < op2pr) {
        return -1;
    }
    else
        return 0;
}