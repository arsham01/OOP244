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
#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H

namespace sdds{
	struct Subject {
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};

//This function will prompt the user to enter the name and checks for error
void read(char* nameOfSubject);

//This function will get the number of sections from user and checks if its in range or not	
void read(int& numOfSections);

//This function will get the number of students in each section and check if its in range or not
void read(int students[], int numOfStudents);

//This function allocates the returned values by other three functions to structure subject
void read(Subject& Sub);

//This function will display the summery of our program
int report(const Subject& Sub);

//This function is for deleting dynamic memories
void freeMem(Subject& Sub);
}

#endif