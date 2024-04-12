#include <time.h>
#include "../include/headerA3.h"

// Menu Option 1:

// This choice enables the user to call a function called 
// "recruitEmployee," which permits them to input the employee's data
// manually through the standard input and adds the information to the 
// end of the provided linked list.

void recruitEmployee(struct employee **headLL)
{
    char tempFname[MAX_LENGTH], tempLname[MAX_LENGTH];

    printf("\nEnter the first name of the employee: ");
    scanf("%s", tempFname);

    printf("Enter the last name of the employee: ");
    scanf("%s", tempLname);

    char more_dependents = 'y';
    int i = 0;

    a3Emp *currPtr = malloc(sizeof(a3Emp));

    char dependentName[MAX_LENGTH];

    currPtr->dependents = malloc(sizeof(char *));
    currPtr->numDependents = 0;

    while (more_dependents == 'y' || more_dependents == 'Y') // if the answer is y or Y, we need to keep on asking the user.
    {
        printf("\nEnter name of dependent #%d: ", i + 1);
        scanf("%s", dependentName);

        currPtr->dependents = realloc(currPtr->dependents, sizeof(char *) * (i + 1));
        currPtr->dependents[i] = malloc(sizeof(char) * (strlen(dependentName) + 1));
        strcpy(currPtr->dependents[i], dependentName);
        currPtr->numDependents++;

        printf("Do you have any more dependents? (y/n) ");
        scanf(" %c", &more_dependents);
        i++;
    }

    int empId = 0;

    for (int j = 0; j < strlen(tempFname); j++)
    {
        empId += tempFname[j];
    }

    empId += strlen(tempLname);

    while(lookOnId ( *headLL, empId) != 0){
        empId = empId + 5;          // this ensures that empId is not the same always, i.e generates random numbers b/w 1 - 999
    }

    printf("\nYou have %d dependents.\n", i); // the total number of dependents

    printf("\nYour computer-generated empId is %d", empId);  // the ID of employee

    struct employee *tempPtr = *headLL;

    while (tempPtr->nextEmployee != NULL)
    {
        tempPtr = tempPtr->nextEmployee;
    }

    strcpy(currPtr->fname, tempFname);
    strcpy(currPtr->lname, tempLname);

    // currPtr->dependents = tempDependents;

    currPtr->empId = empId;

    currPtr->nextEmployee = NULL;

    tempPtr->nextEmployee = currPtr;
}