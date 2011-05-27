/****************************************************
 *Tue 3 Aug, 8:36 PM
 *
 *Objective: Print out the 'This Old Man' song in a
 *way that is not just using the printf() function.
 *
 *A for loop would be a great tool to use in this
 *exercise. There are ten verses in this song.
 *
 ****************************************************/

#include <stdio.h>
#include <string.h>

#define	VERSES 10

int
main(int argc, char *argv[])
{
	int i;
	char *numbers[VERSES] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	char *stuff[VERSES] = {"on my thumb", "on my shoe", "on my knee", "on my door", "on my hive", "on my sticks", "up in heaven", "on my gate", "on my spine", "once again"};
	/* name[size -1] = GOOD; name[size] = BAD; */
	for(i = 0; i < VERSES; i++)
	{
		printf("This old man, he played %s\n", numbers[i]);
		printf("He played knick-knack %s\n", stuff[i]);
		printf("Knick-knack paddywhack, give your dog a bone\n");
		printf("This old man came rolling home\n\n");
	}
	return 0;
}
