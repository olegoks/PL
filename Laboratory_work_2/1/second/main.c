#include <stdio.h>
#define SIZE 5

int main() {

	int arr[SIZE][SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {

			arr[i][j] = rand() % 100;//scanf_s("%d",&arr[i][j]);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	struct StInfo {
		int sum;
		int index;
	}sums[SIZE], temp;
	//StInfo sums[SIZE];

	for(int i = 0; i < SIZE;  i++)
	{
		int sum = 0;

		for (int j = 0; j < SIZE; j++)
		{
			sum += arr[j][i];
			
		}

		sums[i].sum = sum;
		sums[i].index = i;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", sums[i].sum);
	}

	for (int i = 0; i < SIZE- 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (sums[j].sum < sums[j + 1].sum) {
				temp = sums[j];
				sums[j] = sums[j + 1];
				sums[j + 1] = temp;
			}
		}
	}



	printf("\n");

	int arr_2[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		int index = sums[i].index;
		for  (int j = 0; j < SIZE; j++)
		{
			arr_2[j][i] = arr[j][index];

		}
	}

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++)
			printf("%4d  ", arr_2[i][j]);

		printf("\n");


	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d: ", sums[i].sum);//, sums[i].index);
	}

	return 0;
}