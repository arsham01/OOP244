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

#ifndef SDDS_SCHOOL_H
#define SDDS_SCHOOL_H
#include "Subject.h"
namespace sdds
{
  //school structure decleration
  struct School
  {
    int m_noOfSubjects;
    Subject* m_subjects;
    char* m_name;
  };

  //read overload function portotype
  void read(School& school);

  //report overload function portotype
  int report(const School& school);

  //freeMem overload function portotype
  void freeMem(School& school);
}

#endif