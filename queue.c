#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node* link;
};

typedef struct Queue {
	Node* front;
	Node* back;
	int count;
}Queue;

void enqueue(Queue* queue, int nodeData) {
	Node* newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nodeData;
	newNode->link = NULL;

	if (isEmpty(*queue)) {
		queue->front = newNode;
	}

	else {
		queue->back->link = newNode;
	}
	queue->back = newNode;
	queue->count++;
}

int dequeue(Queue* queue) {
	if (isEmpty(*queue)) {
		printf("Queue is empty!\n");
	}

	else {
		Node* temp;
		temp = queue->front;
		int* data = temp->data;
		queue->front = queue->front->link;
		free(temp);
		queue->count--;
		return data;
	}
}

int isEmpty(Queue queue) {
	if (queue.count == 0)
		return 1;
	else
		return 0;
}

int size(Queue queue) {
	return queue.count;
}

int main(void) {
	Queue Q1;
	Q1.front = NULL;
	Q1.back = NULL;
	Q1.count = 0;

	Node* ptr;
	int data = 0;
	int num = 0;
	while (1) {

		scanf("%d", &num);

		if (num > 0) {
			if (size(Q1) < 5) {
				enqueue(&Q1, num);
				printf("Queue size: %d\n", size(Q1));
			}
			else {
				printf("Queue is full!\n");
			}
		}
		else if (num == 0) {
			break;
		}
		else {
			dequeue(&Q1);

		}

		printf("Queue status : ");
		for (ptr = Q1.front; ptr != NULL; ptr = ptr->link) {
			printf("%d ", ptr->data);
		}
		printf("\n");
	}

	return 0;
}