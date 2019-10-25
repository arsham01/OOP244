/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function headers that are related to contacts.
*/
#ifndef SDDS_Contact_H
#define SDDS_Contact_H

#define _CRT_SECURE_NO_WARNINGS

namespace sdds{

struct Contact {
   char name[31];
   long long phoneNumber;
};

//this function will get the phone number and phone number should be long long because we are calling getLongLong function
long long getPhoneNumber();

//this function is for getting contact's name
void getName(char* name);

//this function is for getting contact's name and phone number
void getContact(Contact* C);

//this function used for printing contact's information
void printContact(const Contact* C);

//converting the letters contact's name to lower case letters 
bool nameInContact(const Contact* C, const char* nameSubStr);

//prints all of the contacts informations
void printContacts(const Contact* C, int num);

//compare names
int compare(const Contact* A, const Contact* B);

//sort option
void sort(Contact c[], int n);

//search option
int search(Contact* found, const Contact* C, const char* name, int noOfRecs);
}
#endif