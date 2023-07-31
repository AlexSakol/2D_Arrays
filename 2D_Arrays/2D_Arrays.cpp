#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void massCreate(double** mas, int* n, int* m) {
	for (int i = 0; i < *n; i++) {
		printf("Enter the elements of %d string\n", i);
		for (int j = 0; j < *m; j++) {
			printf("[%d][%d]= ", i, j);
			scanf_s("%lf", *(mas + i) + j);
		}
		printf("\n");
	}

}

void massPrint(double** mas, int* n, int* m) {
	printf("Created array\n");

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			printf("[%d][%d]= %.4lf\t", i, j, *(*(mas + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}

void task1(double** mas, int n, int* m) {// Divide diagonal elements by max
	int i, j;
	double div1, div2;
	double max = **mas;
	for (i = 0; i < n; i++) {
		for (j = 0; j < *m; j++) {
			if (max < mas[i][j]) {
				max = mas[i][j];
			}
		}
	}
	printf("Max=%.4lf\n", max);
	printf("Diagonals divided by max\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < *m; j++) {
			if (i == j) {
				div1 = mas[i][j] / max;
				printf("%.4lf ", div1);
			}
		}
	}
	for (int i = (n - 1); i >= 0; --i)
	{
		div2 = mas[i][n - i - 1] / max;
		printf("%.4lf ", div2);
	}
}



void main() {

	int m, n;
	double** mas;

	printf("Enter the number of rows: ");
	scanf_s("%d", &n);
	printf("\nEnter the number of columns: ");
	scanf_s("%d", &m);

	if (!(mas = new double* [n])) {
		printf("Out of memory\n");
		exit(0);
	}

	for (int i = 0; i < n; i++)
		if (!(*(mas + i) = new double[m])) {
			printf("Out of memory\n");
			mas = NULL;
			exit(0);
		}
	if (n == m) {
		massCreate(mas, &n, &m);
		massPrint(mas, &n, &m);
		task1(mas, n, &m);
	}
	else { printf("Array is not square"); }

	for (int i = 0; i < n; i++)
		delete[](*(mas + i));
	delete[]mas;

	_getch();
}
