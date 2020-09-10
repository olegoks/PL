#include <stdio.h>
#define SIZE 5
int main() {
	
	int arr[SIZE][SIZE];
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			arr[i][j] = (rand() % 100);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%4d  ", arr[i][j]);
		printf("\n");
	}

	int max = -100;
	int i_, j_;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((i == j) && (arr[i][j] > max)) { max = arr[i][j]; i_ = i; j_ = j; }
			if ((i + j == SIZE - 1) && (arr[i][j] > max)) { max = arr[i][j]; i_ = i; j_ = j;}

		}

	}

	printf(" Max: %d ", max);
	printf(" I: %d  J: %d \n", i_, j_);

	int temp = arr[SIZE / 2][SIZE / 2];
	arr[SIZE / 2][SIZE / 2] = arr[i_][j_];
	arr[i_][j_] = temp;
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%4d  ", arr[i][j]);
		printf("\n");
	}
}