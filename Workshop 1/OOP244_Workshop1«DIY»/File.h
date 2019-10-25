/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function headers that are related to files.(editing and reading from the file)
*/
#ifndef SDDS_File_H
#define SDDS_File_H

#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
using namespace std;

namespace sdds{


//read contact's information from the file
bool readContact(Contact* C,FILE* fptr);

//prints contact's information from the file
void writeContact(FILE* fptr, const Contact* C);

//read informations about all of the contacts from file
int readContacts(Contact* contacts, const char* filename);

//prints informations about all of the contacts from file
void writeContacts(Contact* contacts, int cntno, const char* filename);
}
#endif