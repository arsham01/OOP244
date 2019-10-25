/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File report.cpp
// Version 1.0
// Date	2019/09/23
// Author	Fardad Soleimanloo
// Description
// tests Mark data entry
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "MarksReport.h"
int main() {
   sdds::MarksReport mr;
   mr.initialize();
   mr.getMarks();
   mr.print();
   mr.terminate();
   return 0;
}