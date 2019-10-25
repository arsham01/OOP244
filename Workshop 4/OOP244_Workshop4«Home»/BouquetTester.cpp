/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// File BouquetTester.cpp
// Version 1.0
// Date	2019/09/29
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the creation, usage and destruction of the Bouquet class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Flower.h"
#include "Bouquet.h"
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

  // A sample set of flowers to test with.
  Flower f1[3]{ {"Rose", "Red", 2.25} ,{"Rose", "Blue", 3.33} , {"Sunflower", "Yellow", 1.25} };

	cout << "Testing An Empty Bouquet" << endl;
	line(64, '-') << endl;
	number(1) << endl;
	Bouquet b;
	b.display() << endl;

	cout << "Testing A Non-Empty Bouquet 2-Args" << endl;
	line(64, '-') << endl;
	number(2) << endl;
  Bouquet b2 { f1, 3 };
  b2.display() << endl;

	cout << "Testing A Non-Empty Bouquet 3-args" << endl;
	line(64, '-') << endl;
	number(3) << endl;
  Bouquet b3{ f1, 3, "Happy Happy Day" };
  b3.display() << endl;

	cout << "\nTesting Arranging an Empty Bouquet" << endl;
	line(64, '-') << endl;
	number(4) << endl;
  Bouquet b4;
  b4.arrangeBouquet();
  b4.display() << endl;

  cout << "\nTesting Arranging an Non-Empty Bouquet (No Discard)" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  b4.arrangeBouquet();
  b4.display() << endl;

  cout << "\nTesting Arranging an Non-Empty Bouquet (Discard)" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  b4.arrangeBouquet();
  b4.display() << endl;

  cout << "\nTesting Discarding a Bouquet" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  b4.discardBouquet();

	cout << "\nTesting Destructors" << endl;
  line(64, '-') << endl;
  number(8) << endl;

	return 0;
}

/* Expected output

*/