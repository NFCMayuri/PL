// fishc
// Code Check is required bcs DataEraser did't do that
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND NULL
#define MALLOC_FAILED NULL
#define END_OF_LIST NULL

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
            if (person == MALLOC_FAILED)
            {
                printf("ERROR: malloc failed");
                exit(1);
            }
            break;
        }
        case 2: {
            printf("Please input the name:\n");
            struct Person *person = FindPerson(contacts);
            if (person != NOT_FOUND)
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
            if (person == NOT_FOUND)
            {
                printf("The person is not found\n");
            }
            break;
        }
        case 4: {
            printf("Please input the name:\n");
            struct Person *person = DeletePerson(&contacts);
            if (person == NOT_FOUND)
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
        return MALLOC_FAILED;
    }

    GetInput(person);

    // head insert
    if (*contacts != END_OF_LIST)
    {
        // linked-list is not empty
        person->next = *contacts;
        *contacts = person;
    }
    else
    {
        // linked-list is empty
        *contacts = person;
        person->next = NULL;
    }
    return person;
    // return the new-inserted person
}

struct Person *FindPerson(struct Person *contacts)
{
    char temp[40];
    // This should be move to function param

    scanf("%s", temp);
    // Bounds Check Elimination is required

    struct Person *current = contacts;
    while (current != END_OF_LIST && strcmp(current->name, temp))
    {
        current = current->next;
    }

    return current;
}

struct Person *ChangePerson(struct Person *contacts)
{
    struct Person *current = FindPerson(contacts);

    if (current != NOT_FOUND)
    {
        printf("Please input new Phone number:\n");
        scanf("%s", current->phone);
        // Bounds Check Elimination is required
        return current;
    }
    else
    {
        return NOT_FOUND;
    }
}

struct Person *DeletePerson(struct Person **contacts)
{
    struct Person *person = FindPerson(*contacts);

    if (person == NOT_FOUND)
    {
        return NOT_FOUND;
    }
    else
    {
        struct Person *current = *contacts;
        if (current == person)
        {
            // target is the first node
            *contacts = current->next;
            return current;
        }
        else
        {
            while (current->next != person)
            {
                current = current->next;
            }
            struct Person *target = current->next;
            current->next = current->next->next;
            return target;
        }
    }
}

void DisplayContacts(struct Person *contacts)
{
    while (contacts != END_OF_LIST)
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

    while (*contacts != END_OF_LIST)
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
