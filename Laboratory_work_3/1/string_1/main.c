#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 100

int main() {

	typedef unsigned int uint;
	char string[SIZE];
	for (uint i = 0; i < SIZE; i++)string[i] = 0;
	gets(string);


	uint index_end;
	uint index = SIZE - 1;

	while (string[index] == 0) index--;
	index_end = index;
	
	char flag = 1;

	for (uint index = 65; index < 91; index++)
	{
		for (uint i = 0; i <= index_end; i++)
		{
			if ((string[i] == index && string[i - 1] == ' ') || (string[0] == index && flag ==1))
			{

				if (string[0] == index)flag = 0;
				uint j = i;

				while (string[j] != ' ' && j <= index_end) {

					printf("%c", string[j]);
					j++;

				}

				printf(" ");
			}

		}
	}

	return 0;
}