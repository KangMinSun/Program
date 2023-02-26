#pragma warning (disable:4996)
#include <stdio.h>
#define V 6


void init(int arr[][V]) {
	int i, j;
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			arr[i][j] = 0;
		}
	}
}

void addEdge(int arr[][V], int i, int j) {
	arr[i][j] = 1;
	arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V]) {
	int i, j;
	for (i = 0; i < V; i++) {
		printf("%d\t", i);
		for (j = 0; j < V; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j;
	int a[V][V] = { 0 };
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			a[i][j] = 0;
		}
	}
	init(a);
	addEdge(a, 0, 2);
	addEdge(a, 1, 2);
	addEdge(a, 1, 4);
	addEdge(a, 1, 5);
	addEdge(a, 2, 3);
	addEdge(a, 3, 4);
	addEdge(a, 5, 5);
	printAdjMatrix(a);
}