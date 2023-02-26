#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	long n;
	srand(time(NULL));
	n = rand();
	printf("%ld\n", n);
	n = rand();
	printf("%ld\n", n);
	n = rand();
	printf("%ld\n", n);



	return 0;
}