// fishc
// Code Check is required bcs DataEraser did't do that
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define NOT_FOUND -1
// #define MALLOC_FAILED -2
// #define SUCCESS 0
struct Person
{
    char name[20];
    char phone[40];
    struct Person *next;
};

void PrintMenu();
void GetInput(struct Person *person);
void PrintPerson(struct Person *person);

/*
malloc failed -> NULL -> exit(1);
Success -> struct Person*
*/
struct Person *AddPerson(struct Person **contacts);

/*
Not Found -> NULL
Success -> struct Person*
*/
struct Person *ChangePerson(struct Person *contacts);

/*
Not Found -> NULL
Success -> struct Person*
*/
struct Person *DeletePerson(struct Person **contacts);

/*
Not Found -> NULL
Success -> struct Person* -> remember to release!
*/
struct Person *FindPerson(struct Person *contacts);

void DisplayContacts(struct Person *contacts);

inline void ReleasePerson(struct Person *person);

void ReleaseContacts(struct Person **contacts);

int main()
{
    short code;
    struct Person *contacts = NULL;
    PrintMenu();
    while (1)
    {
        printf("Please input the command code:\n");
        scanf("%d", &code);
        switch (code)
        {
        case 0: {
            PrintMenu();
            break;
        }
        case 1: {
            struct Person *person = AddPerson(&contacts);
            if (person == NULL)
            {
                printf("ERROR: malloc failed");
                exit(1);
            }
            break;
        }
        case 2: {
            printf("Please input the name:\n");
            struct Person *person = FindPerson(contacts);
            if (person != NULL)
            {
                PrintPerson(person);
            }
            else
            {
                printf("The person is not found\n");
            }
            break;
        }
        case 3: {
            printf("Please input the name:\n");
            struct Person *person = ChangePerson(contacts);
            if (person == NULL)
            {
                printf("The person is not found\n");
            }
            break;
        }
        case 4: {
            printf("Please input the name:\n");
            struct Person *person = DeletePerson(&contacts);
            if (person == NULL)
            {
                printf("The person is not found\n");
            }
            else
            {
                // ReleasePerson(person);
                free(person);
            }
            break;
        }
        case 5: {
            DisplayContacts(contacts);
            break;
        }
        case 6: {
            goto END;
            break;
        }
        default: {
            break;
        }
        }
    }
END:
    ReleaseContacts(&contacts);
}

void GetInput(struct Person *person)
{
    printf("Please input name:\n");
    scanf("%s", person->name);
    // Bounds Check Elimination is required

    printf("Please input phone number:\n");
    scanf("%s", person->phone);
    // Bounds Check Elimination is required
}

void PrintPerson(struct Person *person)
{
    printf("Name:\n%s\n", person->name);
    printf("Phone number:\n%s\n", person->phone);
}

struct Person *AddPerson(struct Person **contacts)
{
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));

    if (person == NULL)
    {
        return NULL;
    }

    GetInput(person);

    // linked-list is not empty
    if (*contacts != NULL)
    {
        person->next = *contacts;
        *contacts = person;
    }
    else
    {
        *contacts = person;
        person->next = NULL;
    }
    return person;
}

struct Person *FindPerson(struct Person *contacts)
{
    char temp[40];
    // This should be move to function param

    scanf("%s", temp);
    // Bounds Check Elimination is required

    struct Person *current = contacts;
    while (current != NULL && strcmp(current->name, temp))
    {
        current = current->next;
    }

    return current;
}

struct Person *ChangePerson(struct Person *contacts)
{
    struct Person *current = FindPerson(contacts);

    if (current != NULL)
    {
        printf("Please input new Phone number:\n");
        scanf("%s", current->phone);
        // Bounds Check Elimination is required
        return current;
    }
    else
    {
        return NULL;
    }
}

struct Person *DeletePerson(struct Person **contacts)
{
    struct Person *person = FindPerson(*contacts);

    if (person == NULL)
    {
        return NULL;
    }
    else
    {
        struct Person *current = *contacts;
        if (current == person)
        {
            *contacts = current->next;
            // free(current);
            return current;
            // target is the first struct
        }
        else
        {
            while (current->next != person)
            {
                current = current->next;
            }
            struct Person *target = current->next;
            current->next = current->next->next;
            // free(target);
            return target;
        }
        // return NULL;
    }
}

void DisplayContacts(struct Person *contacts)
{
    while (contacts != NULL)
    {
        PrintPerson(contacts);
        contacts = contacts->next;
    }
}

inline void ReleasePerson(struct Person *person)
{
    free(person);
}

void ReleaseContacts(struct Person **contacts)
{
    struct Person *temp = *contacts;

    while (*contacts != NULL)
    {
        temp = *contacts;
        *contacts = (*contacts)->next;
        free(temp);
    }
}

void PrintMenu()
{
    printf("|Welcome to ContactsBook Manager Program|\n");
    printf("|0:print the Menu-----------------------|\n");
    printf("|1:insert new Contact-------------------|\n");
    printf("|2:find for existing Contact------------|\n");
    printf("|3.change existing Contact information--|\n");
    printf("|4.delete existing Contact--------------|\n");
    printf("|5.display all Contact------------------|\n");
    printf("|6.exit---------------------------------|\n");
}
