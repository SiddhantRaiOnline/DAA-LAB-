#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    i = 0;
    j = strlen(str) - 1;

    while(i < j)
    {
        while(str[i] == ' ')
            i++;

        while(str[j] == ' ' || str[j] == '\n')
            j--;

        if(tolower(str[i]) != tolower(str[j]))
        {
            flag = 0;
            break;
        }

        i++;
        j--;
    }

    if(flag == 1)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
