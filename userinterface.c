/*****************************************************************
//
// NAME: Ah Lim Om
//
// HOMEWORK: Project1
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: October 21, 2016
//
// FILE: userinterface.c
//
// DESCRIPTION: This file contains the driver and the user-interface functions
// for Project1 – the bank database application
//
******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
#include "prototypes.h"

int debugmode;
/*****************************************************************
//
// Function name: main
//
// DESCRIPTION: A userinterface function.
// Obtains the argument count and argument vector
// to determine the mode of the program (regular or debug).
//
// Parameters: argc (int) : count for number of argument input
//             argv (char**): array pointer to argument vecter
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int main(int argc, char *argv[])
{
    struct record *start = NULL;

    int choice, index;
    int accountnum, yob;
    char name[25], address[80], tempaccountnum[25], tempname[25], tempaddress[80], tempyob[5], tempchoice[3];

    if (argc == 1)
    {
        debugmode = 0;

        printf("\nWelcome!\n");
        readfile(&start,"inputfile.txt");

    }
    else if (argc == 2 && strcmp(argv[1],"debug") == 0)
    {
        debugmode = 1;

        printf("\n*************************\n");  
        printf("***ENTERING DEBUG MODE***");  
        printf("\n*************************\n");  
        readfile(&start,"inputfile.txt");

    }
    else
    {
        printf("ERROR: Invalid argument\n");
        printf("OPTION: project1 OR project1 debug\n");
        choice = 6;
    }

    while(choice != 6)
    {
        printf("\nMENU\n");
        printf("1. Add Record\n");  
        printf("2. Modify Record\n");   
        printf("3. Print Record Information\n");    
        printf("4. Print all Record\n");    
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("\nPlease enter a number of your choice: ");
        fgets(tempchoice, sizeof(tempchoice), stdin);
        choice = atoi(tempchoice);

        if(choice < 1 || choice > 6)
        {
            printf("\nERROR: Selected choice is not an option!\n");
            printf("Please enter 1 through 6\n");
        }

        if (choice == 1)
        {
            printf("\nPlease enter account number to add: ");
            fgets(tempaccountnum, sizeof(tempaccountnum), stdin);
            accountnum = atoi(tempaccountnum);

            printf("\nPlease enter the name: ");
            fgets(tempname, sizeof(tempname), stdin);
            strcpy(name, tempname);
            name[strlen(name) - 1] = '\0';
            
            printf("\nPlease enter the address (enter '!' on a new line to end):\n");
            getaddress(address, sizeof(address));

            printf("\nPlease enter year of birth: ");
            fgets(tempyob, sizeof(tempyob), stdin);
            yob = atoi(tempyob);
            // clear input buffer
            getchar();

            addRecord(&start, accountnum, name, address, yob);
        }
        else if (choice == 2)
        {
            printf("\nPlease enter account number to modify: ");
            fgets(tempaccountnum, sizeof(tempaccountnum), stdin);
            accountnum = atoi(tempaccountnum);

            printf("\nPlease enter the new address (enter '!' on a new line to end): \n");
            getaddress(address, sizeof(tempaddress));

            modifyRecord(start, accountnum, address);
        }
        else if (choice == 3)
        {
            printf("\nPlease enter account number to view information of: ");
            fgets(tempaccountnum, sizeof(tempaccountnum), stdin);
            accountnum = atoi(tempaccountnum);

            printRecord(start,accountnum);
        }
        else if (choice == 4)
        {
            printAllRecords(start);
        }
        else if (choice == 5)
        {
            printf("\nPlease enter account number to delete: ");
            fgets(tempaccountnum, sizeof(tempaccountnum), stdin);
            accountnum = atoi(tempaccountnum);

            deleteRecord(&start,accountnum);
        }
    }

    if(choice == 6 && debugmode == 1)
    {
            printf("**** PROGRAM EXIT ****\n");
    }
    writefile(start,"output.txt");

}
/*****************************************************************
//
// Function name: getaddress
//
// DESCRIPTION: A userinterface function.
// This function obtains the values of the address from the user
// allows newline until '!' symbol is obtained on a newline
// the function then gets rid of '!' symbol so the pure address
// can be saved on the database.
//
// Parameters: info (char[]) : An array of char to store input address.
//             max (int): maximum number of char array can take
//
// Return values: n/a (void)
//
******************************************************************/
void getaddress(char info[], int max)
{
    char temp[80];

    fgets(temp, sizeof(temp), stdin);
    
    if(temp[strlen(info) - 2] != '!')
    {
        strcpy(info, temp);

        while(temp[strlen(temp) - 2] != '!')
        {
            fgets(temp, sizeof(temp), stdin);
            strcat(info, temp);
        }
    }
    else
    {
        strcpy(info, temp);
    }
    info[strlen(info) - 3] = info[strlen(info) - 2];
    info[strlen(info) - 2] = info[strlen(info) - 1];
    info[strlen(info) - 1] = '\0';
    info[strlen(info) - 2] = '\0';
}