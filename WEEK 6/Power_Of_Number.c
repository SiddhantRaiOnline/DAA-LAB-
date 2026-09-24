#include <stdio.h>
#include <math.h>
int main(void){
    double base, power, result;

    printf("Enter base");
    scanf("%lf",&base);
    
    printf("Enter power");
    scanf("%lf",&power);

    result=pow(base,power);

    printf("%.2lf raised to the power of %.2lf is %.2lf\n",
       base, power, result);

    return 0;
}