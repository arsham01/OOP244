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
// Name   Arsham Yaghoobi         Date  sept-30-2019          Reason
// Fardad
/////////////////////////////////////////////////////////////////
This file contains all of the function definitions.
***********************************************************************/

#include <iostream>
#include "MarksReport.h"
#include "ReportUtils.h"

using namespace std;

namespace sdds{

  void MarksReport::initialize(){
    int numOfMarks;
    char* title;
    title = new char[70];
    cout << "Enter the report Name: ";
    cin.getline(title,70);
    strcpy(m_title,title);
    delete[] title;

    cout << "Enter the number of marks: ";
    cin >> numOfMarks;
    while (cin.get() != '\n');

    m_numOfMarks = numOfMarks;
    new Marks[m_numOfMarks];
  }

  void MarksReport::getMarks(){
   
    cout << "Please enter " << m_numOfMarks << " marks:" << endl;
    int i;
    for (i = 0; i < m_numOfMarks ;i++){
      Mark[i].setEmpty();
			Mark[i].set(DSP_LETTER);
      cout << (i + 1) << ": " ;
      // This while loop is based on the at_home part main module. I just upgraded it with new prompts.
      while (!Mark[i].readName("Subject Name: ", 6) || !Mark[i].read("Mark (mark/outof): ")) {
         cout << "Invalid Entry, retry!\n";
      }
		}
		
    cout << "Entry Completed!" << endl;
		// cout << endl;
    cout << "\n----------------------------------------------------------------------\n";
		// cout << endl;

    }

  void MarksReport::print(){
    Marks report;
    report.setEmpty();
    double gpa = 0.0;
    int high = 0;
    int i =0;
    int low = Mark[0].percent();

    cout << m_title << endl;
    cout << "----------------------------------------------------------------------\n";

    cout << "Marks entered:" << endl;

    for (i = 0; i < m_numOfMarks ; i++){
      Mark[i].display(66) << endl;
    if (Mark[i].percent() <= low) {
				low = Mark[i].percent();
			}
		else if (Mark[i].percent() >= high){
				high = Mark[i].percent();
			}
			gpa =  gpa + Mark[i].letterBasedGPA();
		}
		cout << "----------------------------------------------------------------------\n";

	  // find the lowest mark and its percentage 
		report.set(low, 100);
		report.set(DSP_PERCENT);
		report.set("Lowest Mark");		
		cout << "                              ";
		report.display(36);
    cout << endl;

		// find the highest mark and its percentage 
		report.set(high, 100);
		report.set(DSP_PERCENT);
		report.set("Highest mark");		
		cout << "                              ";
		report.display(36);
    cout << endl;

		// find the GPA 
		report.set(gpa / m_numOfMarks, 4);
		report.set(DSP_GPA);
		report.set("GPA");
		cout << "                              ";
		report.display(36);
    cout << endl;

	}
	
	void MarksReport::terminate() { 
	//	delete[] Mark;
	}


   
  
}
