/* Tue 25 May, 10:54 AM
 *
 * How it works:
 *
 *	“The check digit is the last digit of an ISBN.
 *	 It is calculated on a modulus 11 with weights 10-2,
 * 	 using X in lieu of 10 where ten would
 * 	 occur as a check digit.”
 *
 * 	 In other words, take the beginning number and multiply
 * 	 by one, the second number and multiply by two, the third
 * 	 by three,. . . etc to the tenth number, then divide all 
 * 	 of them by 11. If the ISBN is legit, there will be no
 * 	  remainder.
 *
 */

#include    <stdio.h>

int main(int argc, char *argv[])
{
	long long int isbn, temp;
	int foo, i, exit;

	printf("Please enter an ISBN number without dashes: \n");
	scanf("%lld", &isbn);



	 /* How do you isolate digits?
	 * Remainder when you divide isbn by 10.
	 * Use the modulus operator.
	 */
	
	temp = isbn;
	foo = 0;

	for( i = 10 ; i > 0 ; i-- )
	{
		foo += (temp % 10) * i; 	// gets the rightmost digit
		temp = temp / 10;
	}
	
	printf("%lld", isbn);

	if( foo % 11 == 0 )
	{
		printf("\nYES\n");
	}
	else 
		printf("\nNO\n");	
	
	return 0;
}
