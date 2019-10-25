/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function definitions that are related to contacts.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"
using namespace std;

namespace sdds{
#define MAX_REC_NO 100
//this function will get the phone number and phone number should be long long because we are calling getLongLong function
long long getPhoneNumber() {
   return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
}

//this function is for getting contact's name
void getName(char* name) {
   getStr(name, 30);
}

//this function is for getting contact's name and phone number
void getContact(Contact* C){
   cout << "Name: ";
   getName(C->name);
   cout << "Phone Number: ";
   C->phoneNumber = getPhoneNumber();
}
//this function used for printing contact's information
void printContact(const Contact* C) {
   cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
}
//converting the letters contact's name to lower case letters 
bool nameInContact(const Contact* C, const char* nameSubStr) {
   char name[31];
   char subName[31];
   toLowerCase(name, C->name);
   toLowerCase(subName, nameSubStr);
   return strstr(name, subName) != nullptr;
}
//prints all of the contacts informations
void printContacts(const Contact* C, int num) {
   for (int i = 0; i < num; i++) {
      printContact(&C[i]);
   }
}
//compare names
int compare(const Contact* A, const Contact* B) {
   return strcmp(A->name, B->name);
}
//sort option
void sort(Contact c[], int n) {
   Contact temp;
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         if (compare(&c[j] , &c[j + 1]) > 0) {
            temp = c[j];
            c[j] = c[j + 1];
            c[j + 1] = temp;
         }
      }
   }
}
//search option
int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
   int i;
   int noOfMatches = 0;
   for (i = 0; i < noOfRecs; i++) {
      if (nameInContact(&C[i], name)) {
         found[noOfMatches] = C[i];
         noOfMatches++;
      }
   }
   return noOfMatches;
}
}