#include "../include/headerA3.h"

// Menu Option 9:

//This option executes a function called "fireAll," 
// which removes all the employees from the current linked list.

void fireAll(a3Emp **headLL)
{

    while (*headLL != NULL)     //checks for NULL
    {
        a3Emp *temp = (*headLL)->nextEmployee;      

        free(*headLL);

        *headLL = temp;
    }
}