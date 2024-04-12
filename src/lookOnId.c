#include "../include/headerA3.h"

// Menu Option 4:

// If option 4 is chosen, the program invokes the function "lookOnId"
// to perform the following task: given an empId as input, it searches 
// the current linked list using that empId and returns the position of 
// that employee in the current linked list.

int lookOnId(struct employee *headLL, int whichEmpId)
{
    int current_index = 1; // set at 1

    struct employee *temp = headLL;

// When the function completes its execution, the program prints the obtained information in the main function.

    while (temp != NULL && temp->empId != whichEmpId) 

    {
        temp = temp->nextEmployee;

        current_index += 1;
    }

    if (temp == NULL)       // check for NULL
        return 0;

    return current_index;
}