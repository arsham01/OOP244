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
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main() {
   Mark m1, m2;
   m1.setEmpty();
   cout << "m1: Empty mark: [";
   m1.display() << "]" << endl;
   m1.set(12.5, 20);
   cout << "m1: Display not set: [";
   m1.display() << "]" << endl;
   cout << "m1: Display set to percentage:" << endl;
   m1.set(DSP_PERCENT);
   cout << "m1: 12.5 out ouf 20 is ";
   m1.display() << endl;
   while (!m1.read("Enter Mark for m1 (mark/out_of): ") ){
      cout << "Invalid Mark" << endl;
   }
   cout << "m1: The mark you entered is: ";
   m1.set(DSP_ASIS);
   m1.display() << endl;
   cout << "m1: With the raw value of: ";
   m1.set(DSP_RAW);
   m1.display() << endl;
   cout << "m1: And percentage value of: ";
   m1.set(DSP_PERCENT);
   m1.display() << endl;
   m2.setEmpty();
   cout << "Setting m2 to the raw value of m1..." << endl;
   m2.set(m1.rawValue());
   cout << "done!" << endl;
   cout << "m2: The mark is: ";
   m2.set(DSP_ASIS);
   m2.display() << endl;
   cout << "m2: With the raw value of: ";
   m2.set(DSP_RAW);
   m2.display() << endl;
   cout << "m2: And percentage value of: ";
   m2.set(DSP_PERCENT);
   m2.display() << endl;
   return 0;
}

/*
output:
m1: Empty mark: [Empty Mark object!]
m1: Display not set: [Display mode not set!]
m1: Display set to percentage:
m1: 12.5 out ouf 20 is %63
Enter Mark for m1 (mark/out_of): abc
Invalid Mark, Retry: Enter Mark for m1 (mark/out_of): 12.5/abc
Invalid Mark, Retry: Enter Mark for m1 (mark/out_of): 12.5/20
m1: The mark you entered is: 12.5/20
m1: With the raw value of: 0.625
m1: And percentage value of: %63
Setting m2 to the raw value of m1...
done!
m2: The mark is: 0.625/1
m2: With the raw value of: 0.625
m2: And percentage value of: %63

*/