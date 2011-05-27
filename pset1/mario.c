/*
 * Tue 6 Jul, 12:05 AM
 * 
 * The objective of this exercise is to write
 * a program that recreates the half-pyramid
 * toward the end of World 1-1 in Super Mario
 * Brothers using asterisks (*) for blocks. 
 *
 * It's assumed that the user's terminal is 80
 * characters wide by 24 characters tall.
*/

#include  <stdio.h>
#define WIDTH 80

int enter_height(int height);


int
main(int argc, char *argv[])
{
	int input_height, spaces,
		n_line, blocks, asterisks;
	blocks = 2;
	input_height = enter_height(input_height);
	
	for(n_line = 1; n_line <= input_height; n_line++)
	{
			for(spaces = 0; spaces <= WIDTH - blocks; spaces++)
			{
				printf(" ");

			}
			blocks++;
			for(asterisks = 0; asterisks < WIDTH - spaces; asterisks++)
			{
				printf("*");
			}
			printf("\n");
	}

	
	
	return 0;	
}

int
enter_height(int height)
{
	
	printf("Enter a height for the half pyramid:\n");
	scanf("%d", &height);
	while((height > 23) || (height < 1)){
		printf("Yeah, nice try, but the height must be between 1 and 23.\nTry again.\n");
		scanf("%d", &height);
	}
	printf("\n");
	return height;
}
