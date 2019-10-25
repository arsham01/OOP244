/*
Name:   Arsham Yaghoobi   Student ID:   142927185
This file contains all of the function headers that have no relation with contacts.
*/

#ifndef SDDS_Tools_H
#define SDDS_Tools_H


#define _CRT_SECURE_NO_WARNINGS


using namespace std;

namespace sdds{

//range of input
bool valid(long long min, long long max, long long val);

//getting longlong input
long long getLongLong(long long min, long long max, const char* valueName);

//getting string 
void getStr(char* str, int len);

//converting letters to lowercase
void toLowerCase(char* lowerCase, const char* str);

//yes option
bool yes();
}
#endif