/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File markTester.cpp
// Version 1.0
// Date	2019/09/19
// Author	Fardad Soleimanloo
// Description
// tests Mark data entry
//
// Revision History
// -----------------------------------------------------------
// Name   Arsham Yaghoobi         Date  sept-29-2019          Reason
// Fardad
/////////////////////////////////////////////////////////////////
This file contains function prototypes
***********************************************************************/
#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H
#include "ReportUtils.h"
#include <iostream>
#include <cstring>
namespace sdds{
  class MarksReport {
    Marks Mark[3];
    char m_title[70];
    int m_numOfMarks;

    public :
      void initialize();
      void getMarks();
      void print();
      void terminate();
      
    };
  
}
#endif