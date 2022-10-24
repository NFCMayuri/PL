// fishc
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Date
{
    short year;
    short month;
    short day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
};
void getInput(struct Book *book);
void printBook(struct Book *book);
void InitLibrary(struct Book *library[]);
void printLibrary(struct Book *library[]);
void releaseLibrary(struct Book *library[]);
void getInput(struct Book *book)
{
    printf("Book Title:\n");
    scanf("%s", book->title);
    printf("Book Author:\n");
    scanf("%s", book->author);
    printf("Book Price:\n");
    scanf("%f", &book->price);
    printf("Book Publish Date(2000-12-1):\n");
    scanf("%hd-%hd-%hd", &book->date.year, &book->date.month, &book->date.day);
    printf("Book Publisher:\n");
    scanf("%s", book->publisher);
}
void printBook(struct Book *book)
{
    printf("Book Title:\n%s\n", book->title);
    printf("Book Author:\n%s\n", book->author);
    printf("Book Price:\n%f\n", book->price);
    printf("Book Publish Date:\n%hd-%hd-%hd\n", book->date.year,
           book->date.month, book->date.day);
    printf("Book Publisher:\n%s\n", book->publisher);
}
void InitLibrary(struct Book *library[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        library[i] = NULL;
    }
}
void printLibrary(struct Book *library[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (library[i] != NULL)
        {
            printBook(library[i]);
            putchar('\n');
        }
    }
}
void releaseLibrary(struct Book *library[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (library[i] != NULL)
        {
            free(library[i]);
        }
    }
}
int main()
{
    struct Book *library[MAX_SIZE];
    struct Book *ptr = NULL;
    char ch;
    int index = 0;
    InitLibrary(library);
    while (1)
    {
        printf("Do you need to input information(Y/N):\n");
        do
        {
            ch = getchar();
            // printf("You input %c\n",ch);
        } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

        if (ch == 'Y' || ch == 'y')
        {
            if (index < MAX_SIZE)
            {
                ptr = (struct Book *)malloc(sizeof(struct Book));
                getInput(ptr);
                library[index] = ptr;
                index++;
                putchar('\n');
            }
            else
            {
                printf("Library is full,exiting...\n");
                break;
            }
        }
        else
        {
            break;
        }
    }
    printf("Printing Library......\n");
    printLibrary(library);
    releaseLibrary(library);
}