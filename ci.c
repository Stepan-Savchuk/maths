#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
	double principal;

	printf("Enter initial principal ");
	scanf("%f", &principal);

	double rate;
	printf("Enter a rate ");
        scanf("%f", &rate);

	double n;
	printf("Enter amount of payments ");
        scanf("%f", &n);

	double fr1 = principal*rate * pow( (1 + rate), n);
	if( fr1 == 0.0) printf("\n ERROR! FR1! \n");

	double fr2 = pow( (1 + rate), n) - 1;
	if( fr2 == 0.0) printf("\n ERROR! FR2! \n");
	
	double amount = fr1/fr2;
	if( (amount*0.0) != 0.0) printf("\n ERROR! \n");
	
	printf("%f", amount);
	return 0;
}
