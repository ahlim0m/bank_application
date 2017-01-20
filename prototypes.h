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
// FILE: prototypes.h
//
// DESCRIPTION: This file contains the function prototypes used
//				in project 1 - the bank database application
//
******************************************************************/
int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
void getaddress(char[], int);
