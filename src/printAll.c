#include "../include/headerA3.h"

// Menu Option 2:

// This funtion prints the data of all the employees

void printAll(struct employee *headLL)
{
    int employee_index = 0;

    struct employee *temp = headLL;

    while (temp != NULL)   // check for NULL
    {
        printf("Employee # %d\n", employee_index + 1);
        printf("\tEmployee id: %d\n", temp->empId);
        printf("\tFirst name: %s\n", temp->fname);
        printf("\tLast name: %s\n", temp->lname);
        printf("\tDependents[%d]: ", temp->numDependents);

        for (int i = 0; i < temp->numDependents; i++)  // prints the info of all employees
        {
            printf("%s", temp->dependents[i]);
            if (temp->numDependents != i + 1)
            {
                printf(",");
            }
        }

        printf("\n\n");

        employee_index += 1;

        temp = temp->nextEmployee;
    }

    printf("Currently, there are %d employees", employee_index);
}