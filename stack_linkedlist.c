#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node* link;
};
void push(Node** top, int nodeData) {
	Node* newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nodeData;
	newNode->link = NULL;
	
	if ((*top)!=NULL) {
		newNode->link = (*top);
		*top= newNode;
	}

	else {
		*top = newNode;
	}
}

int pop(Node** stack) {
	if (isEmpty(stack)) {
		printf("stack is empty\n");
	}

	else {
		Node* temp;
		temp = *stack;
		int* data = temp->data;
		*stack = (*stack)->link;
		free(temp);
		return data;
	}
}

int isEmpty(Node** stack) {
	if (*stack == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int size(Node** stack) {
	int size = 0;
	Node* ptr;

	for (ptr = *stack; ptr != NULL; ptr = ptr->link) {
		size += 1;
	}
	return size;
}

int main(void) {
	Node* top = NULL;
	Node* ptr;
	int data = 0;
	int num = 0;
	float plus = 43.00;
	int p = plus;
	printf("%f, %d, %d \n\n", plus, p, '+');

	while (1) { 

		scanf("%d", &num);

			if (num > 0) {
				if (size(&top) < 5) {
					push(&top, num);
					printf("stack size: %d\n", size(&top));
				}
				else {
					printf("stack is full\n");
				}
			}
			else if (num == 0) {
				break;
			}
			else {
				pop(&top);

			}
		
		printf("stack status : ");
		for (ptr = top; ptr != NULL; ptr = ptr->link) {
			printf("%d ", ptr->data);
		}
		printf("\n");
	}
	
	return 0;
}