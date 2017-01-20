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
// FILE: record.h
//
// DESCRIPTION: This file contains the struct named record used
//				in project 1 - the bank database application
//
******************************************************************/
struct record
{
    int              accountno;
    char             name[25];
    char             address[80];
    int              yearofbirth;
    struct record*  next;

};