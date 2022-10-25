// fishc
// Code Check is required bcs DataEraser did't do that
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[20];
    char phone[40];
    struct Person *next;
};
void getInput(struct Person *person);
void printPerson(struct Person *person);
int addPerson(struct Person **contacts);
int changePerson(struct Person *contacts);
int delPerson(struct Person **contacts);
struct Person *findPerson(struct Person *contacts);
void displayContacts(struct Person *contacts);
void releaseContacts(struct Person **contacts);
int main()
{
    short code;
    struct Person *contacts = NULL;
    printf("|Welcome to ContactsBook Manager Program|\n");
    printf("|1:insert new Contact-------------------|\n");
    printf("|2:find for existing Contact------------|\n");
    printf("|3.change existing Contact information--|\n");
    printf("|4.delete existing Contact--------------|\n");
    printf("|5.display all Contact------------------|\n");
    printf("|6.exit---------------------------------|\n");
    while (1)
    {
        printf("Please input the command code:\n");
        scanf("%d", &code);
        switch (code)
        {
        case 1: {
            switch (addPerson(&contacts))
            {
            case -1: {
                printf("ERROR: malloc failed");
                exit(1);
                break;
            }
            case 0: {
                break;
            }
            }
            break;
        }
        case 2: {
            printf("Please input the name:\n");
            struct Person *person = findPerson(contacts);
            if (person != NULL)
            {
                printPerson(person);
            }
            else
            {
                printf("The person is not found\n");
            }
            break;
        }
        case 3: {
            printf("Please input the name:\n");
            switch (changePerson(contacts))
            {
            case -1: {
                printf("The person is not found\n");
                break;
            }
            case 0: {
                break;
            }
            }

            break;
        }
        case 4: {
            printf("Please input the name:\n");
            switch (delPerson(&contacts))
            {
            case -1: {
                printf("The person is not found\n");
                break;
            }
            case 0: {
                break;
            }
            }
            break;
        }
        case 5: {
            displayContacts(contacts);
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
    releaseContacts(&contacts);
}

void getInput(struct Person *person)
{
    printf("Please input name:\n");
    scanf("%s", person->name);
    // Bounds Check Elimination is required
    printf("Please input phone number:\n");
    scanf("%s", person->phone);
    // Bounds Check Elimination is required
}

void printPerson(struct Person *person)
{
    printf("Name:\n%s\n", person->name);
    printf("Phone number:\n%s\n", person->phone);
}

/*
malloc failed -> -1 -> exit(1);
Success -> 0
*/
int addPerson(struct Person **contacts)
{
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
    {
        return -1;
    }
    
    getInput(person);

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
    return 0;
}

/*
Not Found -> NULL
Success -> struct Person*
*/
struct Person *findPerson(struct Person *contacts)
{
    // printf("Please input the name:\n");
    char temp[40];
    // This should be move to function param
    scanf("%s", temp);
    // Bounds Check Elimination is required
    struct Person *current = contacts;
    while (current != NULL && strcmp(current->name, temp))
    {
        current = current->next;
    }
    // if (current != NULL)
    // {
    //     printf("Name:\n%s\n", current->name);
    //     printf("Phone number:\n%s\n", current->phone);
    //     // Maybe this should show in return value instead
    // }
    // else
    // {
    //     printf("Not Found\n");
    //     // Maybe this should show in return value instead
    // }

    return current;
}

/*
Not Found -> -1
Success -> 0
*/
int changePerson(struct Person *contacts)
{
    struct Person *current = findPerson(contacts);
    if (current != NULL)
    {
        printf("Please input new Phone number:\n");
        scanf("%s", current->phone);
        // Bounds Check Elimination is required
        return 0;
    }
    else
    {
        return -1;
    }
}

/*
Not Found -> -1
Success -> 0
*/
int delPerson(struct Person **contacts)
{
    struct Person *person = findPerson(*contacts);
    if (person == NULL)
    {
        return -1;
    }
    else
    {
        struct Person *current = *contacts;
        if (current == person)
        {
            *contacts = current->next;
            free(current);
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
            free(target);
        }
        return 0;
    }
}
void displayContacts(struct Person *contacts)
{
    while (contacts != NULL)
    {
        printPerson(contacts);
        contacts = contacts->next;
    }
}
void releaseContacts(struct Person **contacts)
{
    struct Person *temp = *contacts;
    while (*contacts != NULL)
    {
        temp = *contacts;
        *contacts = (*contacts)->next;
        free(temp);
    }
}