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
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>
namespace sdds{
   const int DSP_RAW = 1;
   const int DSP_PERCENT = 2;
   const int DSP_ASIS = 3;
   const int DSP_UNDEFINED = -1;
   const int DSP_GPA = 4;
   const int DSP_LETTER = 5;

   class Mark {

      int m_displayMode;
      double m_mark;
      int m_outOf;
      char m_name[51];

      void flushKeyboard()const;
      void prnLetter()const;

      public:

         void set(int displayMode);
         void set(double mark, int outOf=1);
         void setEmpty();
         bool isEmpty()const;
         int percent()const;
         double rawValue()const;
         bool read(const char* prompt);
         std::ostream& display(int width = 55)const;
         void set(const char* name);
         void set(const char* name, double rawMark, int outOf =1);
         bool readName(const char* prompt, int maxLen = 50);
         void changeOutof(int value);
         double GPA()const;
         double letterBasedGPA()const;
         

   };
}
#endif