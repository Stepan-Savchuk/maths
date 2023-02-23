#include <stdio.h>

int main(){
	int number;
	int perc;
	printf("Please enter number from which you want to find percentage");
	scanf("%d", &number);
	printf("Please enter percentage of given number you want to find");
	scanf("%d", &perc);
	printf("%d %d", number, perc);
	return 0;
}
