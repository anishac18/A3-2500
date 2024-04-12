#include "../include/headerA3.h"

// Menu Option 6:

// This funtion counts the total number of employees

int countEmployees(a3Emp *headLL)
{
    a3Emp *temp = headLL;

    int count = 0;  // initialized to 0

    while (temp != NULL)
    {
        temp = temp->nextEmployee;
        count += 1;       // counts the employees
    }

    return count;
}