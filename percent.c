#include <stdio.h>

int main(){
	int number;
	int perc;
	printf("Please enter number from which you want to find percentage ");
	scanf("%d", &number);
	printf("\nPlease enter percentage of given number you want to find ");
	scanf("%d", &perc);
	double result = ((number / 100.0) * (float) perc);
	printf("Result %f", result);
	return 0;
}
