#include "../include/headerA3.h"

int main()
{
    int menu_option = 0;
    int whichOne, whichEmpId;
    char sure = 'n';
    char whichName[100];

    a3Emp *headEmployee = NULL;
    struct employee **headLL = &headEmployee;
    char FileName[] = "proFile.txt";
    loadEmpData(headLL, FileName);


    printf("%s", FileName);


    while (1)
    {
        printf("\n\n1. Add a new employee\n2. Print data of all employees\n3. Print data of the nth employee\n4. Search for employee based on empId\n5. Search for employee based on full name\n6. Count the total number of employees\n7. Sort the employees based on their empId\n8. Remove the nth employee in the current LL\n9. Remove all employees in the current LL\n10. Exit\n\n");

        printf("Choose a menu option: ");
        scanf("%d", &menu_option);
        printf("\n");

        switch (menu_option)
        {
        case 1:
            recruitEmployee(headLL);
            break;

        case 2:
            printAll(*headLL);
            break;

        case 3:
            printf("Enter a position: ");
            scanf("%d", &whichOne);
            printOne(*headLL, whichOne);
            break;

        case 4:
            printf("Enter an employee ID: ");
            scanf("%d", &whichEmpId);
            printOne(*headLL, lookOnId(*headLL, whichEmpId));
            break;

        case 5:
            printf("Enter the full name of the employee: ");
            scanf(" %[^\n]s", whichName);
            int x = lookOnFullName(*headLL, whichName);
            // printf("x = %d\n", x);
            if (x == -1)
            {
                printf("Not found\n");
            }
            else
            {
                printOne(*headLL, x);
            }
            break;

        case 6:
            printf("Total number of employees = %d", countEmployees(*headLL));
            break;

        case 7:
            sortEmployeesId(*headLL);
            break;

        case 8:
            printf("Currently there are %d employees.\n", countEmployees(*headLL));

            printf("Which employee do you wish to fire – enter a value between 1 and %d: ", countEmployees(*headLL));
            scanf("%d", &whichOne);
            if (whichOne >= 1 && whichOne <= countEmployees(*headLL))
            {
                fireOne(headLL, whichOne);
                printf("\nThere are now %d employees", countEmployees(*headLL));
            }
            else
            {
                printf("\n Not a valid index");
            }
            break;

        case 9:
        
            printf("\nAre you sure you want to fire everyone(y): ");
            scanf(" %c", &sure);

            if (sure == 'y' || sure == 'Y')
            {
                fireAll(headLL);
                printf("All fired. Linked list is now empty.");
            }
            break;

        case 10:
            exit(0);
            break;

        default:
            printf("Entered options is not valid please enter valid option\n");
        }
    }
}