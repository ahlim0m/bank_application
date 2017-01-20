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
// FILE: database.c
//
// DESCRIPTION: This file contains the database functions
// for Project1 – the bank database application
//
******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
#include "prototypes.h"

extern int debugmode;
/*****************************************************************
//
// Function name: addRecord
//
// DESCRIPTION: A database function.
// This function obtains the information from the user and adds them
// to the database. Records are added sorted by yearofbirth in descending order.
// When same yearofbirth exists, the record is added to the front of the record
// with the same yearofbirth.
//
// Parameters: ptrStart (struct record **) : double pointer to the start of the record
//             uaccountnum (int): user input account number to add
//             uname (char[]): an array of char containing the user input name
//             uaddress (char[]): an array of char containing the user input address
//             uyearofbirth (int): user input year of birth
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int addRecord (struct record ** ptrStart, int uaccountnum, char uname[ ], char uaddress[ ], int uyearofbirth)
{
    struct record ** head = ptrStart;
    struct record * current;
    struct record * previous;

    current = *head;
    previous = current;


    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: addRecord();\n");
        printf("PARAMETERS PASSED:\n");
        printf("Account number: %d\nName: %s\nAddress: \n%s\nYear of birth: %d\n", uaccountnum, uname, uaddress, uyearofbirth);
        printf("*********************************************\n");
    }

    if (*head ==  NULL)
    {
        *head = (struct record *) malloc(sizeof(struct record));
        (*head)->accountno = uaccountnum;
        strcpy(((*head)->name), uname);
        strcpy(((*head)->address), uaddress);
        (*head)->yearofbirth = uyearofbirth;
        (*head)->next = NULL;
    }
    else
    {
        while(current != NULL && current->yearofbirth > uyearofbirth)
        {
            previous = current;
            current = current->next;
        }

        if(current == *head)
        {
            *head = (struct record*)malloc(sizeof(struct record));
            (*head)->accountno = uaccountnum;
            strcpy(((*head)->name), uname);
            strcpy(((*head)->address), uaddress);
            (*head)->yearofbirth = uyearofbirth;
            (*head)->next = current; 
        }
        else
        {
            previous->next = (struct record*)malloc(sizeof(struct record));
            (previous->next)->accountno = uaccountnum;
            strcpy(((previous->next)->name), uname);
            strcpy(((previous->next)->address), uaddress);
            (previous->next)->yearofbirth = uyearofbirth;
            (previous->next)->next = current;       
        }
    }

    printf("\nRECORD ADDED!\n");

    return 0;
}
/*****************************************************************
//
// Function name: printRecord
//
// DESCRIPTION: A database function.
// This function obtains the account number user wants to view info of
// and prints the information. Multiple records are printed if they
// have the same account number. Error message when user input
// account number is not found.
//
// Parameters: ptrStart (struct record *) : pointer to the start of the record
//             uaccountnum (int): user input account number to print record of
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int printRecord (struct record * start, int uaccountnum)
{
    struct record * current;
    int matchFound;

    current = start;
    matchFound = 0;

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: printRecord();\n");
        printf("PARAMETERS PASSED:\n");
        printf("Account number: %d\n", uaccountnum);
        printf("*********************************************\n");
    }

    if(current == NULL)
    {
        printf("\nERROR: List is empty\n");
    }

    while(current != NULL)
    {
        if(current->accountno == uaccountnum)
        {
            printf("\n%d\n%s\n%s\n%d\n", current->accountno, current->name, current->address, current->yearofbirth);
            matchFound = 1;
        }
        current = current->next;
    }

    if(matchFound == 0)
    {
        printf("\nERROR: No Matching Account Number Found!\n");
    }



    return 0;
}
/*****************************************************************
//
// Function name: modifyRecord
//
// DESCRIPTION: A database function.
// This function obtains the account number that the user wants to modify
// address information of, and the new address. Then the program searches
// for matching account number, if found, the address is modified. When
// there are multiple records with same account number, all of them are
// modified.
//
// Parameters: ptrStart (struct record *) : pointer to the start of the record
//             uaccountnum (int): user input account number to modify record of
//             uaddress (char[]): an array of char containing the new user input address
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int modifyRecord (struct record * start, int uaccountnum, char uaddress[ ])
{
    struct record * current;
    current = start;
    int matchFound;

    matchFound = 0;

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: modifyRecord();\n");
        printf("PARAMETERS PASSED:\n");
        printf("Account number: %d\nAddress: \n%s\n", uaccountnum, uaddress);
        printf("*********************************************\n");
    }

    if(current == NULL)
    {
        printf("\nERROR: List is empty\n");
    }

    while(current != NULL)
    {
        if(current->accountno == uaccountnum)
        {
            strcpy(current->address, uaddress);
            printf("\nRECORD MODIFIED!\n");
            matchFound = 1;
        }
        current = current->next;
    }

    if(matchFound == 0)
    {
        printf("\nERROR: No Matching Account Number Found!\n");
    }
    return 0;
}
/*****************************************************************
//
// Function name: printAllRecords
//
// DESCRIPTION: A database function.
// This function obtains the start of the records and prints all
// records stored in the database.
//
// Parameters: ptrStart (struct record *) : pointer to the start of the record
//
// Return values: n/a (void)
//
******************************************************************/
void printAllRecords(struct record * start)
{
    struct record * current;

    current = start;

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: printAllRecords();\n");
        printf("PARAMETERS PASSED:\n");
        printf("*********************************************\n");
    }

    if(current == NULL)
    {
        printf("\nERROR: List is empty!\n");
    }
    else
    { 
        printf("\nPRINTING ALL RECORDS: \n");

        while(current != NULL)
        {
            printf("\n%d\n%s\n%s\n%d\n", current->accountno, current->name, current->address, current->yearofbirth);
            current = current->next;
        }
        printf("\nEND OF THE RECORD\n");
    }
}
/*****************************************************************
//
// Function name: deleteRecord
//
// DESCRIPTION: A database function.
// This function obtains the user input account number to delete record of.
// When matching account number is found, the record gets deleted from the
// database. If there are duplicates, all of them are deleted.
//
// Parameters: ptrStart (struct record **) : double pointer to the start of the record
//             uaccountnum (int): user input account number to delete record of
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int deleteRecord(struct record ** ptrStart, int uaccountnum)
{
    struct record * previous;
    struct record * current;
    struct record * dump;
    int returnValue;
    int matchFound;

    previous = * ptrStart;
    current =  * ptrStart;
    returnValue = -1;
    matchFound = 0;

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: deleteRecord();\n");
        printf("PARAMETERS PASSED:\n");
        printf("Account number: %d\n", uaccountnum);
        printf("*********************************************\n");
    }


    while(current != NULL)
    {
        if(current == *ptrStart)
        {
            if(uaccountnum == current->accountno)
            {
                dump = current;
                *ptrStart = current->next;
                current = current->next;
                previous = previous->next;

                free(dump);
                printf("\nRECORD DELETED!\n");
                matchFound = 1;

                returnValue = 0;
            }
            else
            {
               current = current->next;
            }
        }
        else if(uaccountnum == current->accountno)
        {
            dump = current;
            previous->next = current->next;
            current = current->next;

            free(dump);
            printf("\nRECORD DELETED!\n");
            matchFound = 1;
            returnValue = 0;
        }
        else
        {
            previous = previous->next;
            current = current->next;
        }
    }
    if(matchFound == 0)
    {
        printf("\nERROR: No Matching Account Number Found!\n");
    }
    return returnValue;
}
/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: A database function.
// This function obtains the file name from the user to add the contents
// to the database in the beginning of the program execution.
//
// Parameters: ptrStart (struct record **) : double pointer to the start of the record
//             filename (char[]): an array of char containing the file name
//
// Return values: 0 : success
//                -1 : failed 
//
******************************************************************/
int readfile(struct record ** ptrStart, char filename[ ])
{
    int uaccountnum;
    char uname[25];
    char uaddress[80];
    int uyearofbirth;

    char lines[256];
    int lineNum;
    lineNum = 1;
    
    FILE * inFile = fopen(filename, "r");

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: readfile();\n");
        printf("PARAMETERS PASSED:\n");
        printf("File name: %s\n", filename);
        printf("*********************************************\n");
        printf("\n---Contents of the input file being added---\n\n");


    }

    while(!feof(inFile))
    {
        if(lineNum == 1)
        {
            fgets(lines, sizeof(lines), inFile);
            uaccountnum = atoi(lines);
            lineNum++;
        }
        else if (lineNum == 2)
        {

            fgets(lines, sizeof(lines), inFile);
            strcpy(uname, lines);
            lineNum++;
        }
        else if(lineNum == 3)
        {
            fgets(lines, sizeof(lines), inFile);
            if(lines[strlen(lines) - 2] != '!')
            {
                strcpy(uaddress, lines);

                while(lines[strlen(lines) - 2] != '!')
                {
                    fgets(lines, sizeof(lines), inFile);
                    strcat(uaddress, lines);

                }
                lineNum++;
            }
            else
            {
                strcpy(uaddress, lines);
                lineNum++;
            }
        }
        else
        {
            uname[strlen(uname) - 1] = '\0';
            uaddress[strlen(uaddress) - 2] = uaddress[strlen(uaddress) - 1];
            uaddress[strlen(uaddress) - 2] = '\0';


            fgets(lines, sizeof(lines), inFile);
            uyearofbirth = atoi(lines);

            lineNum = 1;

            addRecord(ptrStart,uaccountnum,uname,uaddress,uyearofbirth);                
        }

    }fclose(inFile);

    return 0;
}
/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: A database function.
// This function obtains the file name from the user to write all the records
// in the database to at the end of the program.
//
// Parameters: ptrStart (struct record *) : pointer to the start of the record
//             filename (char[]): an array of char containing the file name
//
// Return values: n/a (void)
//
******************************************************************/
void writefile(struct record * start, char filename[ ])
{
    struct record * temp;
    FILE *outFile;

    temp = start;

    outFile = fopen(filename, "w");

    if (debugmode == 1)
    {
        printf("\n*********************************************\n");
        printf("FUNCTION CALLED: writefile();\n");
        printf("PARAMETERS PASSED:\n");
        printf("File name: %s\n", filename);
        printf("*********************************************\n");
    }

    while (temp != NULL) 
    {
        fprintf(outFile, "%d\n%s\n%s!\n%d\n", temp->accountno, temp->name, temp->address, temp->yearofbirth);
        temp = temp->next;
    }

    fclose(outFile);
}
