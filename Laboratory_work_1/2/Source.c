#include<time.h>
#define SIZE 3
#include <stdio.h>
int main() {


	int arr[SIZE][SIZE] = {
		{1, -2, 3},
		{1, 2, -3},
		{-1, -2, -3}
	};
	srand(time(NULL));

	/*for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			arr[i][j] = (rand() % 10) - 5;*/

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%4d  ", arr[i][j]);
		printf("\n");
	}

	int stolbec, stroka;
	int number_stroka = 0, number_stolbec = 0;

	for (int i = 0;  i < SIZE;  i++)
	{
		int num_stroka = 0;
		
		for (int j = 0; j < SIZE; j++) {

			if (arr[i][j] < 0)num_stroka++;

		}

		if (num_stroka > number_stroka) {
			number_stroka = num_stroka;
			stroka = i;
		}

	}

	for (int j = 0; j < SIZE; j++)
	{
		int num_stolbec = 0;

		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i][j] > 0) num_stolbec++;

		}

		if (num_stolbec > number_stolbec) {

			number_stolbec = num_stolbec;
			stolbec = j;

		}

	}

	for (int k = 0; k < SIZE; k++)
	{
		arr[stroka][k] = -100;

	}
	for  (int i = 0; i < SIZE; i++)
	{
		arr[i][stolbec] = -100;
	}

	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) { printf("%4d  ", arr[i][j]); }
		printf("\n");
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) { if(arr[i][j] != -100 ) printf("%4d  ", arr[i][j]); }
			
		printf("\n");
	}

	return 0;
}