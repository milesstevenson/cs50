/*************************************************************************
 * Week 2 / Exercise 2
 * 
 * Program encrypts messages using Caesar's cipher.
 * Formula:	Ci = (Pi + K) % 26
 * C1 = New, changed character
 * P1 = First letter of original phrase
 * K = Number the user provides (the key)
 * 26 = Number of letters in the alphabet
 *
 * New = (Original + Key) % 26
 *************************************************************************/
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <ctype.h>

#define CORRECT_INPUT	2		/* two arguments necessary - no more no less*/
#define MAX		80

int num_of_args(int argcount);
void cipher(int key); 			/* all that's required is a cipher key */

int
main (int argc, char *argv[])
{
	int arg_length = strlen(argv[1]);
	int c;	
	char low;

	if (num_of_args(argc) == 1)
		return 1; // exit

	/* is the argument entered a digit? */
	for (int i = 0; i < arg_length; i++) {
		if (!isdigit(argv[1][i])) {
			printf("Character %d is NOT a digit. Make sure"
				" digits are entered next time...\n", i + 1);
			return 2; /* argument entered was not a digit - exit */
			}
	}

	/* convert the character(s) to an integer */
	int k = atoi(argv[1]);
	cipher(k);

	return 0;
}

/* error checking with cmd line arguments */
int num_of_args(int argcount)
{
	/* 2 cmd line arguments is necessary! */
	if (argcount != CORRECT_INPUT)
	{
		printf("\ntoo many arguments entered...\n\n");
		return 1; /* incorrect arguments entered - exit */
	}
	return 0;
}

/* enter some text to be ciphered!		*/
/* cipher = (original + key) % 26	*/
/* a little more to it than that, but read on */
void cipher(int key)
{
	char plain_text[MAX];

	fgets(plain_text, sizeof(plain_text), stdin);
	for (int i = 0; i < strlen(plain_text); i++)
	{
		if (islower(plain_text[i]))
		{
			char low = ((plain_text[i] - 'a' + key) % 26) + 'a'; 
			printf("%c", low);
		}
		else if(isupper(plain_text[i]))
		{
			char high = ((plain_text[i] - 'A' + key) % 26) + 'A';
			printf("%c", high);
		}
		else
			printf("%c", plain_text[i]);
	}
	printf("\n"); /* pretty it up a little... */
}
