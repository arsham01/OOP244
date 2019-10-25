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
// Name   Arsham Yaghoobi         Date  sept-24-2019          Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>
using namespace std;
namespace sdds{
   const int DSP_RAW = 1;
   const int DSP_PERCENT = 2;
   const int DSP_ASIS = 3;
   const int DSP_UNDEFINED = -1;

   class Mark {

      int m_displayMode;
      double m_mark;
      int m_outOf;

      void flushKeyboard()const;

      public:

         void set(int displayMode);
         void set(double mark, int outOf=1);
         void setEmpty();
         bool isEmpty()const;
         int percent()const;
         double rawValue()const;
         bool read(const char* prompt);
         std::ostream& display() const;
   };
}
#endif