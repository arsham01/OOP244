/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function definitions that are related to user interface.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Contact.h"
#include "Tools.h"
#include "File.h"
using namespace std;

namespace sdds{

#define MAX_REC_NO 100


// displays the user interface menu
int menu() {
   cout << endl 
        <<"1- Add Phone Record " << endl;
   cout << "2- Search           " << endl;
   cout << "3- Sort             " << endl;
   cout << "4- List all         " << endl;
   cout << "0- Exit             " << endl;
   cout << "> ";
   return int(getLongLong(0, 4, "option"));
}

//available options
void phoneDir(const char* title, const char* filename) {
   int option;
   Contact C[MAX_REC_NO];
   Contact SearchRes[MAX_REC_NO];
   Contact temp;
   bool changed = false;
   int noOfRecs = readContacts(C, filename);
   int noOfSrchs;
   cout << title << ".................." << endl;
   while ((option = menu())) {
      switch (option){
      case 0:
         cout << "Goodbye!" << endl;
         break;
      case 1: // add
         getContact(&temp);
         C[noOfRecs] = temp;
         noOfRecs++;
         changed = true;
         break;
      case 2: // search
         cout << "Name to search for: ";
         getStr(temp.name, 30);
         noOfSrchs = search(SearchRes, C, temp.name, noOfRecs);
         if (noOfSrchs) {
            printContacts(SearchRes, noOfSrchs);
         }
         else {
            cout << temp.name << ", not found!" << endl;
         }
         break;
      case 3:  // Sort
         sort(C, noOfRecs);
         changed = true;
         cout << "Sorted!" << endl;
         break;
      case 4:
         printContacts(C, noOfRecs);
         break;
      }
   }
   if (changed) {
        cout << "Goodbye!" << endl;
      cout << endl << "The phone diecotry has changed!" << "Save changes? (Y/N): ";
      if (yes()) {
         writeContacts(C, noOfRecs, filename);
         cout << "Changes Saved!!" << endl;
      }
      else {
         cout << "Changes aborted!!" << endl;
      }
   }

}
}
