/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads DIY
// File RobotSquadTester.cpp
// Version 1.0
// Date	2019/10/05
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the RobotSquad class and its ability to resize a roster of Robots
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "RobotSquad.h"
#include "RobotSquad.h"

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
  // Robots for creating squads with
  Robot r1("Joe", 200, 300, 700), r2("Ippo", 300, 200, 800), r3("Miyata", 200, 400, 500);
  Robot r4("Takamura", 400, 400, 1000), r5("Ricardo", 400, 400, 800), r6("Robo", 1, 1, 1);

  cout << "Empty Squad, default constr" << endl;
	line(64, '-') << endl;
  number(1) << endl;
  RobotSquad rs1;
  rs1.display();

  cout << "\nAdd Members to Empty Squad" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  rs1 += r1;
  rs1.display();

  cout << "\nSubstract members from an Empty Squad" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  RobotSquad rs2("Gold");
  --rs2;

  cout << "\nSubtract members from a Non-Empty Squad" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  cout << "Before subtraction" << endl;
  line(64, '-') << endl;
  rs1.display();
  --rs1;
  cout << "\nAfter subtraction" << endl;
  line(64, '-') << endl;
  rs1.display();

  cout << "\nFill up Squads" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  rs1 += r1;
  rs1 += r2;
  rs1 += r3;
  rs2 += r4;
  rs2 += r5;
  rs2 += r6;
  rs1.display();
  line(64, '-') << endl;
  rs2.display();

  cout << "\nBox one member from each Squad" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  box(rs1.getRoster()[0], rs2.getRoster()[2]);
  box(rs1.getRoster()[1], rs2.getRoster()[0]);
  box(rs1.getRoster()[2], rs2.getRoster()[1]);

  cout << "\nDisplay the condition of each Squad after boxing" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  rs1.display();
  rs2.display();

  return 0;
}