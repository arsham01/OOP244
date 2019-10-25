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

#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds{
   void Mark::flushKeyboard()const{
      char newline = '\0';
      while(newline != '\n'){
         newline = cin.get();
      }
   }


   void Mark::set(int displayMode){
      m_displayMode = displayMode;
   }

   
   void Mark::set(double mark, int outOf){
      m_mark = mark;
      m_outOf = outOf;
      //if (outOf == '\0'){
      //   outOf = 1;
      //}
   }

   void Mark::setEmpty(){
      m_displayMode = DSP_UNDEFINED;
      m_mark = -1;
      m_outOf = 100;
   }


   bool Mark::isEmpty()const{
      
      return m_displayMode == DSP_UNDEFINED && m_mark == -1 && m_outOf == 100;
         
   }

   
   int Mark::percent()const{
      int percentage;
      percentage = (m_mark / m_outOf) * 100 + 0.5;
      return percentage;
   }

   
   double Mark::rawValue()const{
      double val;
      val = m_mark / m_outOf;
      return val;
   }

   
   bool Mark::read(const char* prompt){
      bool success = true;
      cout << prompt;
      cin >> m_mark;
      cin.ignore();
      cin >> m_outOf;
      if (cin.fail()){
         cin.clear();
         setEmpty();
         success = false;
      }

      flushKeyboard();
      return success;
   }

   
   std::ostream& Mark::display() const{
         if (isEmpty()){
            cout << "Empty Mark object!";
         }
         else if (m_displayMode == DSP_RAW){
            cout << rawValue();
         }

         else if (m_displayMode == DSP_PERCENT){
            cout << "%" << percent();
         }

         else if (m_displayMode == DSP_ASIS){
            cout << m_mark << "/" << m_outOf;
         }

         else if (m_displayMode == DSP_UNDEFINED){
            cout << "Display mode not set!";
         }

         else 
            cout << "Invalid Mark Display setting!";
      

      return cout; 
   }
}
