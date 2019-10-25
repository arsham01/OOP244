// Robot.h
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
the robot.
***********************************************************************/
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include "Parts.h"
#include <iostream>
namespace sdds{
  class Robot {
    #define NICK_MAX_LEN 10

    char r_nickname[NICK_MAX_LEN + 1];
    int r_durability;
    Arms r_arms;
    Legs r_legs;


    public:

    Robot();
    void AllocateMemoryForNickName();
    void AllocateMemoryForDurability();
    void safeEmptyState();
    bool isEmpty() const;
    Robot(const char* nickName, int armsForce, int speedOfLegs , int robotDurability);
    std::ostream& display() const;
    Arms getArms() const;
    Legs getLegs() const;
    int getDurability();
    operator bool() const;
    Robot& operator-=(int durability);
  };

  void box(Robot& firstRobot, Robot& secondRobot);
}

#endif
