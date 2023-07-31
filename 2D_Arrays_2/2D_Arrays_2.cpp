#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

void task1(int* mas, int n, int m) { // average of columns with negative elements
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			double average = 0, sum = 0;
			if (*(mas + i * m + j) < 0) {
				count++;
				printf("Column with negative elements\n");
				for (int i = 0; i < n; i++) {
					printf("%5d\n", *(mas + i * m + j));
					sum += *(mas + i * m + j);
					average = sum / n;
				}
				printf("Average %.4lf\n", average);
			}
		}
	}
	if (count == 0) { printf("Columns with negative elements do not exist\n"); }

}


void main() {

	int* mass, i, j, n, m;

	printf("Strings: ");
	scanf_s("%d", &n);
	printf("Columns: ");
	scanf_s("%d", &m);

	mass = (int*)malloc(n * m * sizeof(int));

	if (!mass) { printf("Out of memory\n"); }
	else {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("a[%d][%d] = ", i, j);
				scanf_s("%d", (mass + i * m + j));
			}
		}
		printf("\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("%5d ", *(mass + i * m + j));
			}
			printf("\n");
		}
		task1(mass, n, m);
	}
	_getch();
	free(mass);
}

