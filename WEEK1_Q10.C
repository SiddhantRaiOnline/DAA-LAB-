#include <stdio.h>

int main()
{
    float balance = 10000;
    float amount;
    float transactions[5];
    int count = 0;
    int choice, i;

    while(1)
    {
        printf("\n\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Show Last 5 Transactions");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Balance = %.2f", balance);
        }

        else if(choice == 2)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            balance = balance + amount;

            if(count < 5)
            {
                transactions[count] = amount;
                count++;
            }
            else
            {
                for(i = 0; i < 4; i++)
                    transactions[i] = transactions[i + 1];

                transactions[4] = amount;
            }

            printf("Money deposited successfully");
        }

        else if(choice == 3)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if(amount <= balance)
            {
                balance = balance - amount;

                if(count < 5)
                {
                    transactions[count] = -amount;
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = -amount;
                }

                printf("Money withdrawn successfully");
            }
            else
            {
                printf("Insufficient balance");
            }
        }

        else if(choice == 4)
        {
            printf("\nLast 5 Transactions:\n");

            for(i = 0; i < count; i++)
            {
                if(transactions[i] > 0)
                    printf("Deposited: %.2f\n", transactions[i]);
                else
                    printf("Withdrawn: %.2f\n", -transactions[i]);
            }
        }

        else if(choice == 5)
        {
            printf("Thank you");
            break;
        }

        else
        {
            printf("Invalid choice");
        }
    }

    return 0;
}