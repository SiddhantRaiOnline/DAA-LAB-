#include <stdio.h>
#include <time.h>

long long power(int base, int n)
{
    if (n == 0)
        return 1;

    long long half = power(base, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main()
{
    int base, n;
    long long result;
    clock_t start, end;
    double time_taken;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter power: ");
    scanf("%d", &n);

    start = clock();

    result = power(base, n);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Result = %lld\n", result);
    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}