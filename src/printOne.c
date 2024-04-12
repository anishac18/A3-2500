#include "../include/headerA3.h"

// Menu Option 3:

// This function requires an integer input as a sequence number
// and outputs the employee data from the current linked list that
// corresponds to that position.

void printOne(struct employee *headLL, int whichOne)
{
    int current_position = 1; // we assumed that  head of the linked list is at position 1.

    struct employee *temp = headLL;

    while (current_position != whichOne && temp != NULL)
    {
        temp = temp->nextEmployee;
        current_position += 1;
    }

    if (temp == NULL)  // check for NULL
    {
        printf("Not employee data found at %d", whichOne);
        return;
    }

    printf("\nEmployee id: %d", temp->empId); // prints the information of employee at the given position
    printf("\nFirst name: %s", temp->fname);
    printf("\nLast name: %s", temp->lname);
    printf("\nDependents: ");
    for (int i = 0; i < temp->numDependents; i++)
    {
        printf("%s", temp->dependents[i]);
        if (temp->numDependents != i + 1)
        {
            printf(",");
        }
    
    }
}