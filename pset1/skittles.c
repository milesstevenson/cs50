#include  <stdio.h>
#include  <stdlib.h>
#include <time.h>

int
main(int *argc, char *argv[])
{
	// seed PRNG
	srand(time(NULL));

	// pick pseudorandom number in {0, 1023}
	int skittles = rand() % 1024;

	for (int i = 0; i < 10; i++)
		printf("%d\n", skittles);
	return 0;
}

