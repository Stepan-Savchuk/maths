#include <stdio.h>
#include <math.h>

int main(){
	double principal = 4200.0;

	double rate = 12.5;

	double n = 2;
	
	double amount = (principal * rate * pow( (1+rate), n ) ) / ( pow( (1 + rate), n )-1);
	
	printf("%f", amount);
	return 0;
}
