#include "../include/headerA3.h"

// Menu Option 8:

// This option invokes a function called "fireOne," which prompts 
// the user to enter a value between 1 and the total number of employees 
// in the current linked list.

void fireOne(a3Emp **headLL, int whichOne)
{
    int current_index = 1;  // set to 1

    a3Emp *temp = *headLL;
    a3Emp *prev = NULL;    

    while (current_index != whichOne)
    {
        prev = temp;
        temp = temp->nextEmployee;
        current_index += 1;
    }

    if (prev == NULL)       // check for NULL
    {
        *headLL = temp->nextEmployee;       
    }
    else
    {
        prev->nextEmployee = temp->nextEmployee;
    }

    printf("Employee [Id: %d] fired", temp->empId);

    free(temp);
}