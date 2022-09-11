#define _CRT_SEUCURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t) )

void sort(int[], int);

int main(void)
{
	int i, n;
	int list[MAX_SIZE];
	
	FILE* fp = fopen("data2.txt", "w");

	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);
	if (n<1 || n>MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; i++) {
		list[i] = rand() % 1000;
		fprintf(fp, "%d ", list[i]);
	}
	sort(list, n);
	fprintf(fp, "\n Sorted array: \n");
	for (i = 0; i < n; i++) {
		fprintf(fp, "%d ", list[i]);
	}
	fprintf(fp, "\n");


}

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}