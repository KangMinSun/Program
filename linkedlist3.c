#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node* prev;
	Node* next;
};

void add(Node** list, int nodeData) {
	Node* newNode;
	Node* ptr;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nodeData;
	newNode->prev = NULL;
	newNode->next = NULL;


	if (*list == NULL) {
		newNode->prev = NULL;
		newNode->next = NULL;
		*list = newNode;
	}
	else {
		ptr = *list;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newNode;
		newNode->prev = ptr;
	}

}

Node* delete(Node** list, int num) {
	Node* ptr = NULL;
	Node* garbage = NULL;

	//*list == head

	if (*list != NULL) {
		if ((*list)->data == num) {
			garbage = *list;
			*list = (*list)->next;
			(*list)->prev = NULL;
			ptr = *list;
		}
		else {
			for (ptr = *list; ptr->next != NULL; ptr = ptr->next) {
				if (ptr->data == num)
					break;
			}

			ptr->prev->next = ptr->next;
			garbage = ptr;
		}

		free(garbage);
	}
	return ptr;
}

int main() {
	Node* head = NULL;
	Node* ptr;
	Node* ptr2 = NULL;
	int i, n;
	int num = -1;

	n = 10;

	for (i = 1; i <= n; ++i) {
		add(&head, i);
	}

	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d ", ptr->data);
		ptr2 = ptr;
	}
	printf("\n");

	for (; ptr2 != NULL; ptr2 = ptr2->prev) {
		printf("%d ", ptr2->data);
	}

	printf("\n=====================\n");
	printf("====리스트 생성완료====\n");
	printf("=======================\n");

	for (i = 0; i < 5; i++) {
		printf("리스트에서 삭제할 숫자를 입력하세요 : ");
		scanf("%d", &num);
		if (!delete(&head, num)) {
			printf("리스트에 해당 숫자가 없습니다.\n");
		}
		else {
			for (ptr = head; ptr != NULL; ptr = ptr->next) {
				printf("%d ", ptr->data);
			}
			printf("\n");
		}
	}

	return 0;
}