/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
// File RobotTester.cpp
// Version 1.0
// Date	2019/10/05
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Robot and Arms classes through the use of their public members
// In particular their operators.
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

  cout << "Testing Empty Pair of Arms (default)" << endl;
	line(64, '-') << endl;
  number(1) << endl;
  Arms a1;
  cout << "a1 arms: " << a1.getForce();

  cout << "\nPrefix ++ on Empty Arms" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Arms a2 = ++a1;
  cout << "a1 arms: " << a1.getForce() << endl;
  cout << "a2 arms: " << a2.getForce() << endl;;

  cout << "\nPostfix ++ on Non Empty Arms" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  Arms a3 = a1++;
  cout << "a1 arms: " << a1.getForce() << endl;
  cout << "a3 arms: " << a3.getForce() << endl;

  cout << "\nTesting Non Empty Arms (2 arg)" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  Arms a4(0);
  Arms a5(7);
  cout << "a4 arms: " << a4.getForce() << endl;
  cout << "a5 arms: " << a5.getForce() << endl;

  cout << "\nTesting An Empty Robot" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  Robot r1;
  r1.display();

  cout << "\nTesting An Non Empty Robot" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  Robot r2("Mechanick", 0, 0);
  Robot r3("Ippo", 70, 600);
  r2.display() << endl;
  r3.display();

  cout << "\nTesting A Robot to Bool conversion" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  if (r1) cout << "r1 results in a true value" << endl;
  if (!r2) cout << "r2 results in a false value" << endl;

  return 0;
}