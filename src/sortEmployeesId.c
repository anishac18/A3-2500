#include "../include/headerA3.h"

// Menu Option 7:

// This funtion sorts and prints the Employee information in ascending order of employee ID.

void sortEmployeesId(struct employee *headLL)
{
    struct employee *temp = headLL;

    struct sorted_employee
    {
        int empId;
        struct employee *employee;
        struct sorted_employee *nextEmployee;
    };

    struct sorted_employee *head = NULL;

    while (temp != NULL)
    {
        struct sorted_employee *node = malloc(sizeof(struct sorted_employee));

        node->empId = temp->empId;
        node->employee = temp;
        node->nextEmployee = NULL;

        if (head == NULL)       // checks for NULL
        {
            head = node;
        }
        else
        {
            struct sorted_employee *prev = NULL;
            struct sorted_employee *tempSorted = head;

            while (tempSorted != NULL && tempSorted->empId < node->empId)
            {
                prev = tempSorted;
                tempSorted = tempSorted->nextEmployee;
            }

            if (prev == NULL)
            {
                node->nextEmployee = head;
                head = node;
            }
            else
            {
                node->nextEmployee = prev->nextEmployee;
                prev->nextEmployee = node;
            }
        }

        temp = temp->nextEmployee;
    }

    printf("After sorting on empId, the employees are as follows: \n\n");
    int employee_index = 1;   // set to 1
    while (head != NULL)
    {
        printf("Employee # %d\n", employee_index);
        printf("\tEmployee id: %d\n", head->employee->empId);
        printf("\tFirst name: %s\n", head->employee->fname);
        printf("\tLast name: %s\n", head->employee->lname);
        printf("\tDependents[%d]: ", head->employee->numDependents);

        for (int i = 0; i < head->employee->numDependents; i++)
        {
            printf("%s", head->employee->dependents[i]);  // prints all the information of the employee in ascending order
            if (head->employee->numDependents != i + 1)
            {
                printf(",");
            }
        }

        printf("\n\n");

        employee_index += 1;

        head = head->nextEmployee;
    }
}