#include <stdio.h>

int main(){
	int number;
	int perc;

	printf("Please enter number from which you want to find percentage ");
	scanf("%d", &number);
	printf("\nPlease enter percentage of given number you want to find ");
	scanf("%d", &perc);

	double result = ((number / 100.0) * (float) perc);
	printf("Result %f\n", result);
	
	printf("Please enter a percentage from which you wanna find full number ");
	scanf("%d", &perc);
	printf("Please enter a number of given percentage ");
	scanf("%d", &number);
	

	result = 100 / (perc / number);

	int fn;

	printf("Please enter a full number from which you wanna find percentage ");                                           scanf("%d", &fn);
        printf("Please enter a number of which you wanna find percentage "
);                                                                 scanf("%d", &number);

	result = ( (float) number / (float) fn) * 100.0;

	printf("Result %f\% \n", result);
	return 0;
}
