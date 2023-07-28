#include <stdio.h>
#include <stdlib.h>

/**
int main ()
{
	int myArray[4];
	myArray[0] = 777;
	myArray[3] = 2;

	for (int i = 0; i < 4; i++)
		printf("%d\n", myArray[i]);

	return (0);
}
*/

int main ()
{
	int *myArray = malloc(sizeof(int) * 4);
	int checker = 0;

	myArray[3] = 77;
	while (myArray)
	{
		if (checker > 10)
			break;
		printf("%d\n", *myArray);
		checker++;
		myArray++;
	}

	return (0);
}
