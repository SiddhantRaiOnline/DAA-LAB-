#include <stdio.h>

int main()
{
    int a[100], n, i;
    int max, second;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    max = a[0];
    second = -999999;

    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            second = max;
            max = a[i];
        }
        else if(a[i] > second && a[i] != max)
        {
            second = a[i];
        }
    }

    if(second == -999999)
        printf("Second largest element does not exist");
    else
        printf("Second largest element = %d", second);

    return 0;
}