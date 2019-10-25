/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads AT HOME
// File RobotTester2.cpp
// Version 1.0
// Date	2019/10/05
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Robot, Arms, Legs classes through the use of their public members
// In particular their operators and helper functions.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Robot.h"
#include "Robot.h"
#include "Parts.h"
#include "Parts.h"

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

int main() {

  cout << "Testing Creating Legs, Empty & Non-Empty" << endl;
	line(64, '-') << endl;
  number(1) << endl;
  Legs l1, l2(-13), l3(50);
  cout << l1.getSpeed() << " " << l2.getSpeed() << " " << l3.getSpeed() << endl;

  cout << "\n -= on Empty & Non-Empty Legs" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  l1 -= 5; l2 -= 10; l3 -= 15;
  cout << l1.getSpeed() << " " << l2.getSpeed() << " " << l3.getSpeed() << endl;

  cout << "\nCompare the speed of Legs" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  if (l1 < l3) cout << "l1 is slower than l3" << endl;
  if (l3 > l2) cout << "l3 is faster than l2" << endl;

  cout << "\nTesting Non-Empty Robot w/ Legs" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  Robot r1("Miyata", 120, 120, 500), r2("Ippo", 150, 100, 600);
  r1.display(); r2.display();

  cout << "\nTesting -= on a Robot's durability" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  Robot r3("Takamura", 200, 200, 1000);
  r3 -= 50;
  r3.display();

  cout << "\nTesting box function (no bout)" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  Robot r4;
  box(r3, r4);

  cout << "\nTesting box function (bout)" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  box(r1, r2);

  return 0;
}