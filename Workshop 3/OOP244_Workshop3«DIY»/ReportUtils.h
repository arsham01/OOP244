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
#ifndef SDDS_REPORTUTILS_H__
#define SDDS_REPORTUTILS_H__
#include "MarksReport.h"
#include <iostream>
namespace sdds {

   const int DSP_RAW = 1;
   const int DSP_PERCENT = 2;
   const int DSP_ASIS = 3;
   const int DSP_UNDEFINED = -1;
   const int DSP_GPA = 4;
   const int DSP_LETTER = 5;

  class Marks{

    double m_marks;
    int m_outOf;
    char m_name[21];
    int m_display;

    void flushKeyboard()const;
    void prnLetter()const;

    public:
      void set(int displayMode);
      void set(double marks, int outOf = 1);
      void setEmpty();
      bool isEmpty()const;
      int percent()const;
      double rawValue()const;
      bool read(const char* prompt);
      void set(const char* name);
      void set(const char* name, double rawMark, int outOf =1);
      bool readName(const char* prompt, int maxLen = 50);
      void changeOutof(int value);
      double GPA()const;
      double letterBasedGPA()const;
      std::ostream& display(int width = 65) const;
  };
}
#endif