#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node* link;
};

void add(Node** list, int nodeData) {
	Node* newNode;
	Node* ptr;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nodeData;
	newNode->link = NULL;

	if (*list == NULL) {
		*list = newNode;
	}
	else {
		ptr = *list;
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = newNode;
	}

}

Node* delete(Node** list, int num) {
	Node* ptr=NULL;
	Node* garbage=NULL;

	//*list == head

	if (*list != NULL) {
		if ((*list)->data == num) {
			garbage = *list;
			*list = (*list)->link;
			ptr = *list;
		}
		else {
			for (ptr = *list; ptr->link != NULL; ptr = ptr->link) {
				if (ptr->link->data == num)
					break;
			}
			garbage = ptr->link;
			ptr->link = ptr->link->link;
		}

		free(garbage);
	}
	return ptr;
}

int main() {
	/*
	Node* head = NULL;

	Node node1;
	node1.data = 0;
	node1.link = NULL;

	Node node2;
	node2.data = 0;
	node2.link = NULL;

	Node node3;
	node3.data = 0;
	node3.link = NULL;

	node1.data = 1;
	node2.data = 2;
	node3.data = 3;

	head = &node1;
	node1.link = &node2;
	node2.link = &node3;

	Node* ptr;
	for (ptr = head;ptr!=NULL; ptr = ptr->link) {
		printf("%d\n", ptr->data);
	}
	*/

	Node* head = NULL;
	Node* ptr;
	int i, n;
	int num = -1;

	n = 10;

	for (i = 1; i <= n; ++i) {
		add(&head, i);
	}
	
	for (ptr = head; ptr != NULL; ptr = ptr->link) {
		printf("%d ", ptr->data);
	}

	printf("\n=====================\n");
	printf("====리스트 생성완료====\n");
	printf("=======================\n");

	for (i = 0; i < 5; i++) {
		printf("리스트에서 삭제할 숫자를 입력하세요 : ");
		scanf("%d", &num);
		if (!delete(&head,num)) {
			printf("리스트에 해당 숫자가 없습니다.\n");
		}
	 	else {
			for (ptr = head; ptr != NULL; ptr = ptr->link) {
				printf("%d ", ptr->data);
			}
			printf("\n");
		}
	}

	return 0;
}