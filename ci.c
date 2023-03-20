#include <stdio.h>
#include <math.h>

int main(){
	double principal = 4200.0;
	double amount = principal * (pow( (1.0 + (2.5/2.0)), (2.0*5.0) ));
	printf("%f", amount);
	return 0;
}
