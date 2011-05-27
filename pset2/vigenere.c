/***************************************************************************
 * FILENAME: vigenere.c
 *
 * Tue 23 Nov, 8:36 PM
 *
 * Pset 2 - 3 of 3
 * Write a program that encrypts messages using Vigenere's cipher. 
 * Must accept a single command-line argument: a keyword, k, composed
 * entirely of alphabetical characters.
 *
 * Ci = (Pi + Ki) % 26
 **************************************************************************/

#include  <stdio.h>  /* printf(), fgets()		*/
#include  <ctype.h>  /* isalpha(), isupper(), islower()	*/
#include  <string.h> /* strlen()			*/
#include  <stdlib.h> /* sizeof()			*/

/***************************************************************************
 defined constants */
#define     MAX			80 /* max string length			*/
#define     CORRECT_INPUT	2  /* correct amount of arguments	*/
/***************************************************************************
 prototypes */
int arg_check(int argcount);
void cipher(char *key);
int alpha_check(char *string[]);

/***************************************************************************
 main */
int
main(int argc, char *argv[])
{
	if (arg_check(argc) == 1)
		return 1; /* exit */
	if (alpha_check(argv) == 2)
		return 2; /* exit */
	char *key = argv[1];

	cipher(key);

	return 0;
}

/***************************************************************************
 error checking w/ cmd line arguments */
int arg_check(int argcount)
{
	if (argcount != CORRECT_INPUT) {
		printf("Two arguments is the requirement"
		       " to run this application.\n");
		return 1; /* exit */
	}
	return 0;
}

/***************************************************************************
 error checking - is the string an array of alphabetical characters? */
int alpha_check(char *string[])
{
	int len = strlen(string[1]);

	for (int i = 0; i < len; i++) {
		if (!isalpha(string[1][i])) {
			printf("The keyword must consist of"
			       " alphabetical characters.\n");
			return 2;
		}
	}
	return 0;
}

/***************************************************************************
 * cipher the text now that you have a key
 *
 * mod operator is important here
 * make sure not to go beyond the bounds of the array
 **************************************************************************/

void cipher(char *key)
{
	char text[MAX];
	fgets(text, sizeof(text), stdin);
	int j = 0;

	for (int i = 0; i < strlen(text); i++) {
		j = j % strlen(key);
		if (isupper(text[i])) { /* if text char is upper	*/
			if (isupper(key[j])) { /* if key char is upper	*/
				char upper = (((text[i] - 'A') + (key[j] - 'A')) % 26) + 'A';
				printf("%c", upper);
				//printf("%d\t%c\t%c\t%d\n",j, key[j], upper, upper);
				j++;
			}
		}
		else if (isupper(text[i])) {
			if (islower(key[j])) { /* if key char is upper	*/
				char lower = (((text[i] - 'a') + (key[j] - 'a')) % 26) + 'a';
				printf("%c", lower);
				//printf("%d\t%c\t%c\t%d\n",j, key[j], upper, upper);
				j++;
			}
		}
		else if (islower(text[i])) {
			if (isupper(key[j])) { /* if key char is upper	*/
				char upper = (((text[i] - 'A') + (key[j] - 'A')) % 26) + 'A';
				printf("%c", upper);
				//printf("%d\t%c\t%c\t%d\n",j, key[j], upper, upper);
				j++;
			}
		}
		else if (islower(text[i])) {
			if (islower(key[j])) { /* if key char is upper	*/
				char lower = (((text[i] - 'a') + (key[j] - 'a')) % 26) + 'a';
				printf("%c", lower);
				//printf("%d\t%c\t%c\t%d\n",j, key[j], upper, upper);
				j++;
			}
		}
		else
			printf("%c", text[i]);
	}

	printf("\n");	
}
