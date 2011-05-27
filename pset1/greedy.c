/* Sun 4 Jul, 11:38 PM
 * The objective of this application is 
 * to use the greedy algorithm to display
 * the least amount of coins that can be 
 * used in USD for change owed.
 */

#include  <stdio.h>

#define     QUARTER	0.25
#define     DIME	0.10
#define     NICKLE	0.05
#define     PENNY	0.01

int main(int argc, char *argv[])
{
	float changeOwed, changeCount;
	int coins;

	printf("How much change is necessary:\n");
	scanf("%f", &changeOwed);
	
	if( changeOwed < 0 )
	{
		do{
		printf("Yeah right, buddy. How much change do you really need?\n");
		scanf("%f", &changeOwed);
		} while (changeOwed < 0);
	}
	
	changeCount = 0;
	coins = 0;
	
	while((changeOwed >= QUARTER) && ((changeOwed - changeCount) >= QUARTER)){
		coins++;
		changeCount += QUARTER;
	}
	
	while((changeOwed >= DIME) &&((changeOwed - changeCount) >= DIME)){
		coins++;
		changeCount += DIME;
	}

	while((changeOwed >= NICKLE) &&((changeOwed - changeCount) >= NICKLE)){
		coins++;
		changeCount += NICKLE;
	}

	while((changeOwed >= PENNY) &&((changeOwed - changeCount) >= PENNY)){
		coins++;
		changeCount += PENNY;
	}

	printf("I owe you %d coins.\n", coins);
	return 0;
}
