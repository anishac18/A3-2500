#include "../include/headerA3.h"

// Menu Option 5:

// If option 5 is chosen, the program invokes the function "lookOnFullName"
// to execute the following task: provided with the full name of an employee
// as input, it searches the current linked list using that name and returns the
// position of the employee in the linked list. After the function completes its
// execution, the program prints the resulting information in the main function.

int lookOnFullName(struct employee *headLL, char whichName[100])
{
    int current_index = 1; // set to 1
    // int found = 0;
    // int retVal = 0;

    struct employee *temp = headLL;

    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];

    while (temp != NULL) // when it's not equal to NULL
    {
        strcpy(firstName, temp->fname);
        strcpy(lastName, temp->lname);
        // strcat(firstName, " ");
        // strcat(firstName, lastName);
        // printf("%s\n", firstName);
        if (strcmp(whichName, strcat(strcat(firstName, " "), lastName)) == 0) // Check if the entered name is equal to or not to the first name + last name
        {
            return current_index;
        }
        current_index += 1;
        temp = temp->nextEmployee; // searches for employee information based on full name
    }

    return -1;
}