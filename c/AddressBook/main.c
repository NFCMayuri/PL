// fishc
// Code Check is required bcs DataEraser did't do that
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
void addPerson(struct Person **contacts);
void changePerson(struct Person *contacts);
void delPerson(struct Person **contacts);
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
            addPerson(&contacts);
            break;
        }
        case 2: {
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
            changePerson(contacts);
            break;
        }
        case 4: {
            delPerson(&contacts);
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
void addPerson(struct Person **contacts)
{
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
    {
        printf("ERROR: malloc failed");
        exit(1);
    }
    if (contacts != NULL)
    {
        getInput(person);
        person->next = *contacts;
        *contacts = person;
    }
    else
    {
        *contacts = person;
        person->next = NULL;
    }
}
struct Person *findPerson(struct Person *contacts)
{
    printf("Please input the name:\n");
    char temp[20];
    scanf("%s", temp);
    // Bounds Check Elimination is required
    struct Person *current = contacts;
    while (current != NULL && strcmp(current->name, temp))
    {
        current = current->next;
    }
    if (current != NULL)
    {
        printf("Name:\n%s\n", current->name);
        printf("Phone number:\n%s\n", current->phone);
    }
    else
    {
        printf("Not Found\n");
    }

    return current;
}
void changePerson(struct Person *contacts)
{
    struct Person *current = findPerson(contacts);
    if (current != NULL)
    {
        printf("Please input new Phone number:\n");
        scanf("%s", current->phone);
        // Bounds Check Elimination is required
        printf("Done");
    }
    else
    {
        printf("Not Found\n");
    }
}
void delPerson(struct Person **contacts)
{
    struct Person *person = findPerson(*contacts);
    if (person == NULL)
    {
        printf("Not Found");
    }
    else
    {
        struct Person *current = *contacts;
        if (current == person)
        {
            *contacts = current->next;
            // the first struct is target
        }
        else
        {
            while (current->next != person)
            {
                current = current->next;
            }
            current->next = current->next->next;
        }
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