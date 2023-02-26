#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node* link;
};


int main() {
	Node head = { -1, NULL };

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
	node2.data = 10;
	node3.data = 100;

	head.link = &node1;
	node1.link = &node2;
	node2.link = &node3;


	printf("%d\n", head.link->data);
	printf("%d\n", head.link->link->data);
	printf("%d\n", head.link->link->link->data);
	printf("========================\n");

	Node* ptr;

	ptr = &head;

	// ptr->link == *ptr.link
	ptr = ptr->link;
	printf("%d\n", ptr->data);

	ptr = ptr->link;
	printf("%d\n", ptr->data);

	ptr = ptr->link;
	printf("%d\n", ptr->data);

	printf("========================\n");


	ptr = head.link;
	while (ptr!=NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}

	printf("========================\n");


	for (ptr = head.link; ptr != NULL; ptr = ptr->link){
		printf("%d\n", ptr->data);
	}


	return 0;
}