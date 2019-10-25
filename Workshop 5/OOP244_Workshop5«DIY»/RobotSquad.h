// RobotSquad.h
/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads AT HOME
// File RobotTester2.cpp
// Version 1.0
// Date    2019/10/05
// Author    Hong Zhan (Michael) Huang
// Description
// Tests the Robot, Arms, Legs classes through the use of their public members
// In particular their operators and helper functions.
//
// Revision History
// -----------------------------------------------------------
// Name  Arsham Yaghoobi          Date   oct-10-2019         Reason
// Michael
/////////////////////////////////////////////////////////////////
This file contains all of the functions and operators prototypes related to
the robot squad.
***********************************************************************/
#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H

#include "Robot.h"
namespace sdds {
	class RobotSquad {
		char rs_name[11];
		Robot* rs_robotRoster;
		int rs_robotRosterCount;
	public:
		RobotSquad();
    void AllocateMemoryForName(const char* str);
    void AllocateMemoryForRoster();
    void AllocateMemoryForRosterCount();
		RobotSquad(const char* str);
		~RobotSquad();
		std::ostream& display() const;
		void setEmpty();
		bool isEmpty() const;

	
		
		Robot* getRoster()const;
		RobotSquad& operator+=(Robot robot);
		RobotSquad& operator--();



	};
	
}
#endif