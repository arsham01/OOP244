/***********************************************************************
// OOP244 Workshop 2: read functions for foolproof integer and C string
//                    data entry
// File	utils.cpp
// Version 1.0
// Date	2019/09/15
// Author	Fardad Soleimanloo
// Description
// 
// Revision History
// -----------------------------------------------------------
// Name    Arsham Yaghoobi        Date Sept-18-2019           Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Subject.h"
#include "utils.h"
using namespace std;

namespace sdds{

//This function will prompt the user to enter the name and checks for error
void read(char* subjectName){
  cout << "Enter subject name: ";
  const char* errorMessage = "Name is too long, only 70 characters allowed!\nRedo Entry: ";
  read(subjectName, 70, errorMessage);
}

//This function will get the number of sections from user and checks if its in range or not
void read(int& sectionsNum){
  cout << "Enter number of sections: ";
  const char* ErrorMess = "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ";
  read(sectionsNum, 1, 10, ErrorMess);
}

//This function will get the number of students in each section and check if its in range or not
void read(int studentsNum[], int numOfStudents ){
  cout << "Enter the number of students in each one of the " << numOfStudents <<" sections:\n";
  const char* ErrorMess = "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ";
  for (int i =0; i < numOfStudents; i++){
    cout << i+1 << ": ";
    read(studentsNum[i],5,35,ErrorMess);
  }
}
//This function allocates the returned values by other three functions to structure subject
void read(Subject& subject){
  char name[71];
  read(name);
  subject.m_subjectName = new char[strlen(name) + 1];
  strcpy(subject.m_subjectName, name);
    
  int* addressOfSections = nullptr;
  addressOfSections = new int;
  subject.m_noOfSections = addressOfSections;
  read(*addressOfSections);
    

  int* numOfstdInSections = nullptr;
  numOfstdInSections = new int[*addressOfSections];
  subject.m_noOfStdsInSecs = numOfstdInSections;
  read(numOfstdInSections, *addressOfSections);
 }

//This function will display the summery of our program
int report(const Subject& subject){
  for (int i = 0; i < *subject.m_noOfSections; i++){
    cout << subject.m_noOfStdsInSecs[i];
    if (i < *subject.m_noOfSections - 1){
      cout << ",";
    }
  }

  cout << "\n";
  cout << subject.m_subjectName << ": ";
  int sum = 0;
  for (int i = 0; i < *subject.m_noOfSections; i++){
    sum += subject.m_noOfStdsInSecs[i];
  }
  cout << sum << "\n";
  return sum;
 }
//This function is for deleting dynamic memories
void freeMem(Subject& subject){
  delete[] subject.m_subjectName;
  delete subject.m_noOfSections;
  delete[] subject.m_noOfStdsInSecs;
  }
}