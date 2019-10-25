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
This file contains all of the function definitions.
***********************************************************************/

#include <iostream>
#include <cstring>
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
      strcpy(m_name,"\0");
   }


   bool Mark::isEmpty()const{
      
      return  m_mark == -1;
         
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

   
   std::ostream& Mark::display(int width) const{
      if (strcmp(m_name,"\0") > 0){
         cout.fill('.');
         cout.width(width);
         cout.setf(ios::left);
         cout << m_name;
      }
         if (isEmpty()){
            cout << "Empty Mark object!";
         }
         else if (m_displayMode == DSP_RAW){
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << rawValue();
         }

         else if (m_displayMode == DSP_PERCENT){
            cout << "%" << percent();
         }

         else if (m_displayMode == DSP_ASIS){
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << m_mark << "/" << m_outOf;
         }

         else if (m_displayMode == DSP_UNDEFINED){
            cout << "Display mode not set!";
         }

         else if (m_displayMode == DSP_LETTER){
            prnLetter();
         }

         else if (m_displayMode == DSP_GPA){
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << GPA();
         }

         else 
            cout << "Invalid Mark Display setting!";
      

      return cout; 
   }

   void Mark::prnLetter()const{
      if (!isEmpty()){
         int percentage = percent();
         if(percentage >= 0 && percentage <= 49){
            cout << "F";
         }
         else if (percentage >= 50 && percentage <= 54 ){
            cout << "D";
         }
         else if (percentage >= 55 && percentage <= 59 ){
            cout << "D+";
         }
         else if (percentage >= 60 && percentage <= 64){
            cout << "C";
         }
         else if (percentage >= 65 && percentage <= 69){
            cout << "C+";
         }
         else if (percentage >= 70 && percentage <= 74){
            cout << "B";
         }
         else if (percentage >= 75 && percentage <= 79){
            cout << "B+";
         }
         else if (percentage >= 80 && percentage <= 89){
            cout << "A";
         }
         else if (percentage >= 90 && percentage <= 100){
            cout << "A+";
         }
         else{
            cout << "?";
         }
      }
   }

   void Mark::set(const char* name){
      strcpy(m_name,name);
   }

   void Mark::set(const char* name, double rawMark, int outOf){
      set(name);
      set(rawMark,outOf);
      
   }

   bool Mark::readName(const char* prompt, int maxLen){
      cout << prompt;
      bool resOf = true;
      cin.getline(m_name,maxLen + 1);
      if (cin.fail()){
         cin.clear();
         flushKeyboard();
         strcpy(m_name,"\0");
         resOf = false;
      }
      return resOf;
   }

   void Mark::changeOutof(int value){
      m_outOf = value;
      double val = m_mark * (double(value)) / m_outOf;

      if (val < 1){
         setEmpty();
      }
   }

   double Mark::GPA()const{
      return rawValue()*4;
   }

   double Mark::letterBasedGPA()const{
      int percentage = (int(m_mark / m_outOf * 100) + 0.5);
      double GPA = 0;
      if (percentage >= 0 && percentage <= 49){
         return GPA = 0.0;
      }
      else if (percentage >= 50 && percentage <= 54){
         return GPA = 1.0;
      }
      else if (percentage >= 55 && percentage <= 59){
         return GPA = 1.5;
      }
      else if (percentage >= 60 && percentage <= 64){
         return GPA = 2.0;
      }
      else if (percentage >= 65 && percentage <= 69){
         return GPA = 2.5;
      }
      else if (percentage >= 70 && percentage <= 74){
         return GPA = 3.0;
      }
      else if (percentage >= 75 && percentage <= 79){
         return GPA = 3.5;
      }
      else if (percentage >= 80 && percentage <= 89){
         return GPA = 4.0;
      }
      else if (percentage >= 90 && percentage <= 100){
         return GPA = 4.0;
      }
      return GPA;
   }
}

   
