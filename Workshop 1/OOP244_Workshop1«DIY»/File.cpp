/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function definitions that are related to files.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "Contact.h"
using namespace std;
namespace sdds{

#define MAX_REC_NO 100

//read contact's information from the file
bool readContact(Contact* C,FILE* fptr) {
   return fscanf(fptr,"%[^,],%lld", C->name, &C->phoneNumber) == 2;
}

//prints contact's information from the file
void writeContact(FILE* fptr, const Contact* C) {
   fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
}
//read informations about all of the contacts from file
int readContacts(Contact* contacts, const char* filename) {
   FILE* fptr = fopen(filename, "r");
   Contact C;
   int num;
   for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
      contacts[num] = C;
   }
   return num;
}

//prints informations about all of the contacts from file
void writeContacts(Contact* contacts, int cntno, const char* filename) {
   FILE* fptr = fopen(filename, "w");
   int num;
   for (num = 0; num < cntno; num++) {
      writeContact(fptr, &contacts[num]);
   }
   fclose(fptr);
}
}