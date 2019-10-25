/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy AT HOME
// File markAtHomeTester.cpp
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
#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
ostream& line(int len, char ch) {
   for (int i = 0; i < len; i++, cout << ch);
   return cout;
}
ostream& number(int num) {
   cout << num;
   for (int i = 0; i < 9; i++) {
      cout << " - " << num;
   }
   return cout;
}
void listMarks(const Mark* marks, int num) {
   Mark result;
   result.setEmpty();
   double gpa = 0;
   int aver = 0;
   int i;
   for (i = 0; i < num; i++) {
      marks[i].display(60) << endl;;
      aver += marks[i].percent();
      gpa += marks[i].letterBasedGPA();
   }
   line(64, '-') << endl;
   result.set(gpa / num, 4);
   result.set(DSP_GPA);
   result.set("GPA");
   line(30, ' ') ;
   result.display(30) << endl;
   result.set(aver / num, 100);
   result.set(DSP_PERCENT);
   result.set("Average");
   line(30, ' ');
   result.display(30) << endl;
}
int main() {
   Mark m[3];
   Mark test;
   int i;
   cout << "Enter 3 marks: " << endl;
   for (i = 0; i < 3; i++) {
      m[i].setEmpty();
      m[i].set(DSP_LETTER);
      number(i + 1) << ":" <<endl;
      while (!m[i].readName("Subject Name: ", 6) || !m[i].read("Mark: ")) {
         cout << "Invalid Entry, retry!" << endl;
         m[i].set(DSP_LETTER);
      }
   }
   listMarks(m, 3);
   test.setEmpty();
   for (i = -1; i <= 21; i++) {
      cout << i << ": -------------------" << endl;
      for (int j = 1; j <= 5; j++) {
         test.set(j);
         test.set(double(i), 20);
         test.display() << endl;
      }
      if (i < 0) i += 8;
   }
   return 0;
}

/*
Enter 3 marks:
1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1:
Subject Name: WEB2222
Invalid Entry, retry!
Subject Name: WEB222
Mark: a;sldkfj
Invalid Entry, retry!
Subject Name: WEB222
Mark: 12/13
2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2:
Subject Name: OOP244
Mark: 15/20
3 - 3 - 3 - 3 - 3 - 3 - 3 - 3 - 3 - 3:
Subject Name: DBS211
Mark: 18/20
WEB222......................................................A+
OOP244......................................................B+
DBS211......................................................A+
----------------------------------------------------------------
                              GPA...........................3.8
                              Average.......................%85
-1: -------------------
Empty Mark object!
Empty Mark object!
Empty Mark object!
Empty Mark object!
Empty Mark object!
8: -------------------
0.40
%40
8.0/20
1.6
F
9: -------------------
0.45
%45
9.0/20
1.8
F
10: -------------------
0.50
%50
10.0/20
2.0
D
11: -------------------
0.55
%55
11.0/20
2.2
D+
12: -------------------
0.60
%60
12.0/20
2.4
C
13: -------------------
0.65
%65
13.0/20
2.6
C+
14: -------------------
0.70
%70
14.0/20
2.8
B
15: -------------------
0.75
%75
15.0/20
3.0
B+
16: -------------------
0.80
%80
16.0/20
3.2
A
17: -------------------
0.85
%85
17.0/20
3.4
A
18: -------------------
0.90
%90
18.0/20
3.6
A+
19: -------------------
0.95
%95
19.0/20
3.8
A+
20: -------------------
1.00
%100
20.0/20
4.0
A+
21: -------------------
1.05
%105
21.0/20
4.2
?


*/