// Parts.h
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
This file contains all of the functions and operators prototypes related to parts of
the robot.
***********************************************************************/

#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds{
  class Arms {
    const int MIN_FORCE = 50;
    int a_force;

    public :

    Arms();
    void AllocateMemoryForForce();
    Arms(int armsForce);
    bool isEmpty() const;
    int getForce() const;
    Arms& operator++();
    Arms operator++(int);
    Arms& operator+=(int add);

  };

  class Legs{
    const int MIN_SPEED = 25;
    int l_speed;

    public:

    Legs();
    void AllocateMemoryForSpeed(int val);
    Legs(int legsSpeed);
    bool isEmpty() const;
    int getSpeed() const;
    Legs& operator-=(int PassedInt);
  };

  bool operator>(const Legs& firstSet, const Legs& secondSet);
  bool operator<(const Legs& firstSet, const Legs& secondSet);
  bool operator>(const Arms& firstSet, const Arms& secondSet);
  bool operator<(const Arms& firstSet, const Arms& secondSet);
}

#endif
