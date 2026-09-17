#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main()
{
    struct Book b[50];
    int n = 0;
    int choice, id, i;

    while(1)
    {
        printf("\n\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Display Unavailable Books");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter title: ");
            scanf("%s", b[n].title);

            printf("Enter author: ");
            scanf("%s", b[n].author);

            printf("Enter total copies: ");
            scanf("%d", &b[n].total);

            b[n].available = b[n].total;

            n++;

            printf("Book added successfully");
        }

        else if(choice == 2)
        {
            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++)
            {
                if(b[i].id == id)
                {
                    printf("\nTitle: %s", b[i].title);
                    printf("\nAuthor: %s", b[i].author);
                    printf("\nTotal copies: %d", b[i].total);
                    printf("\nAvailable copies: %d", b[i].available);
                    break;
                }
            }

            if(i == n)
                printf("Book not found");
        }

        else if(choice == 3)
        {
            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++)
            {
                if(b[i].id == id)
                {
                    if(b[i].available > 0)
                    {
                        b[i].available--;
                        printf("Book issued");
                    }
                    else
                    {
                        printf("Book is unavailable");
                    }
                    break;
                }
            }

            if(i == n)
                printf("Book not found");
        }

        else if(choice == 4)
        {
            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++)
            {
                if(b[i].id == id)
                {
                    if(b[i].available < b[i].total)
                    {
                        b[i].available++;
                        printf("Book returned");
                    }
                    else
                    {
                        printf("All copies are already available");
                    }
                    break;
                }
            }

            if(i == n)
                printf("Book not found");
        }

        else if(choice == 5)
        {
            printf("\nUnavailable Books:\n");

            for(i = 0; i < n; i++)
            {
                if(b[i].available == 0)
                {
                    printf("\nID: %d", b[i].id);
                    printf("\nTitle: %s", b[i].title);
                    printf("\nAuthor: %s\n", b[i].author);
                }
            }
        }

        else if(choice == 6)
        {
            break;
        }

        else
        {
            printf("Invalid choice");
        }
    }

    return 0;
}