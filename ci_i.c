#include <stdio.h>
#include <math.h>

int main(){
        double principal;
	printf("Enter initial principal ");
        scanf("%lf", &principal);

        int rate;
	printf("Enter a rate ");
        scanf("%d", &rate);

        int n;
	printf("Enter amount of payments per year ");
        scanf("%d", &n);

	int years;
	printf("Enter amount of years ");
        scanf("%d", &years);

        double amount = principal * pow( (1.0 + rate/100.0), ( (double) n * (double) years) );

        printf("%lf", amount);
        return 0;
}
