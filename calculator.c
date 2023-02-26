#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node Node;
typedef struct node{
    float data;   // 숫자 스택용 
    //char operator[1];  // 기호 스택용
    //struct node* link;
    Node* link;
} num_Node;

typedef struct node2{    
    Node* top;
    int count;
} usr_Stack;

//함수 원형
void push(usr_Stack* stk, float data); // 스택의 제일 위에 data값을 가진 노드 삽입
float pop(usr_Stack* stk); //스택의 제일 위 노드를 제거하고 그 data값을 반환
int isStackEmpty(usr_Stack* stk); //스택이 비어있으면 1(True)반환, 아니면 0(False)반환
void clear(usr_Stack* stk); // 스택의 모든 노드 제거(구현 및 사용 해도 되고 안해도 됨)

char* postfix(char* str, char* str2); // 중위 표현식(문자열)을 입력받아 후위 표현식(문자열)로 변환 및 반환하는 함수
float calculate(char* str); //후위 표현식(문자열)을 입력받아 계산법에 따라 계산한 뒤 결과값(실수)를 반환하는 함수 
float operation(float op1, float op2); //피연산자 두 개와 연산자를 입력받아서 그에 맞게 사칙연산 수행 후 결과값 반환
int OperationPriority(float op); //연산자 우선순위 따지기

int main() {

    char str[30]; // 입력되는 수식을 담을 문자 배열
    char str2[30]; // 후위 표현식으로 전환된 수식이 담기는 문자 배열
    int len1; // 중위 표현식 문자열의 길이
    int len2; // 후위 표현식 문자열의 길이
    float result; // 계산 결과값
    
    scanf("%s", str);
    //gets(str);
    //char str[30] = ['1', '+', '2', '*', '3', '+', '4', '/', '5', '\0'];
    
    postfix(str, str2);
    printf("main() %s\n", str2);
    result = calculate(str2);
    printf("결과값 : %f", result);

    //스택 동작 확인 코드
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