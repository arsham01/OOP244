/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function definitions that have no relation with contacts.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

namespace sdds{
#define MAX_REC_NO 100

//range of input
bool valid(long long min, long long max, long long val) {
   return min <= val && val <= max;
}
//getting longlong input
long long getLongLong(long long min, long long max, const char* valueName) {
   long long val;
   bool done = false;
   while (!done) {
      cin >> val;
      if (cin.fail()) {
         cin.clear();
         cout << "Bad Number, try again: ";
      }
      else {
         if (!valid(min, max, val)) {
            cout << "Invalid " << valueName << "!" << endl 
            << "The "<< valueName <<" must be between " << min << " and " << max << ": ";
         }
         else {
            done = true;
         }
      }
      cin.ignore(1000, '\n');
   }
   return val;
}
//getting string 
void getStr(char* str, int len) {
   cin.getline(str, len, '\n');
}
//converting letters to lowercase
void toLowerCase(char* lowerCase, const char* str) {
   int i;
   for (i = 0;str[i] && i < 30; i++) {
      lowerCase[i] = str[i] | 0x20;
   }
   lowerCase[i] = 0;
}
//yes option
bool yes() {
   char ch;
   ch = cin.get();
   cin.ignore(1000, '\n');
   return ch == 'y' || ch == 'Y';
   }
}