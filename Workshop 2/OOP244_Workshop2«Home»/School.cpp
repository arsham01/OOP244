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


#include <iostream>
#include<cstring>
#include "School.h"
#include "Subject.h"
#include "utils.h"
using namespace std;

namespace sdds {

void read(School& school)
  {
    cout << "Please enter the name of the school:\n> ";
    char SchoolName[61];
    read(SchoolName, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");
    school.m_name = new char[strlen(SchoolName) + 1];
    strcpy(school.m_name, SchoolName);


    cout << "Please enter the number of subjects offered by " << school.m_name << ": ";
    read(school.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

    school.m_subjects = new Subject[school.m_noOfSubjects];
    for (int i = 0; i < school.m_noOfSubjects; i++)
    {
      cout << i + 1 << ") ------------------------------" << endl;
      read(school.m_subjects[i]);
    }
  }

int report(const School& school) {
int total = 0, sctstd = 0;
cout << school.m_name<< endl;
cout << "Subject Enrollments" << endl;

for (int i = 0; i < school.m_noOfSubjects; i++)
		{
			for (int j = 0; j < *school.m_subjects[i].m_noOfSections; j++)
			{
				if (j == (*school.m_subjects[i].m_noOfSections) - 1)
					cout << school.m_subjects[i].m_noOfStdsInSecs[j]<<endl;
				else
					cout << school.m_subjects[i].m_noOfStdsInSecs[j] << ",";

				sctstd += school.m_subjects[i].m_noOfStdsInSecs[j];
			}
            cout << school.m_subjects[i].m_subjectName << ": " << sctstd << endl;
            total += sctstd;
            sctstd = 0;
		}
cout <<"Total enrollment: "<< total;
cout << endl;
return total;

}

void freeMem(School& school)
{
    delete[] school.m_name;
    delete[] school.m_subjects;
}


}
