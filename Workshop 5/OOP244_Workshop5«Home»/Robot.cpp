// Robot.cpp
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
This file contains all of the functions and operators definition related to
the robot.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Parts.h"
#include "Robot.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds{
  Robot::Robot(){
    safeEmptyState();
  }

  void Robot::safeEmptyState(){
    AllocateMemoryForNickName();
    AllocateMemoryForDurability();
    r_arms.AllocateMemoryForForce();
  }

  void Robot::AllocateMemoryForNickName(){
    strcpy(r_nickname,"");
  }

  void Robot::AllocateMemoryForDurability(){
    r_durability = 0;
  }

  Robot::Robot(const char* nickName, int armsForce, int speedOfLegs , int robotDurability){
   if (nickName == nullptr || strcmp(nickName, "") == 0){
      safeEmptyState();
    }
    else{
      strcpy(r_nickname, "");
      if (strlen(nickName) > NICK_MAX_LEN){
        for (int i = 0; i < NICK_MAX_LEN; i++){
          r_nickname[i] = nickName[i];
        }
      }
      else{
        strcpy(r_nickname, nickName);
      }
      
      if (robotDurability < 1){
        r_durability = 100;
      }
      else{
        r_durability = robotDurability;
      }

      Arms a{ armsForce };
      r_arms += a.getForce();
      Legs l{ speedOfLegs };
      r_legs.AllocateMemoryForSpeed(l.getSpeed());
    }
  }
  bool Robot::isEmpty() const{
    return strcmp(r_nickname, "") == 0 && r_durability == 0 && r_arms.isEmpty() && r_legs.isEmpty();
  }

  ostream& Robot::display() const{
    if (isEmpty()){
      cout << "This Robot isn’t operational" << endl;
    }
    else{
      cout << "***Robot Summary***" << endl;
      cout << "Nickname: " << r_nickname << endl;
      cout << "Arm Power: " << r_arms.getForce() << endl;
      cout << "Durability: " << r_durability << endl;
      cout << "Legs: " << r_legs.getSpeed() << endl;
    }
        return cout;
  }


  Arms Robot::getArms() const{
    Arms a{ r_arms.getForce() };
    return a;
  }

  Legs Robot::getLegs() const{
    Legs l{ r_legs.getSpeed() };
    return l;
  }

  Robot::operator bool() const {
        bool result;
    if (strcmp(r_nickname, "") == 0 || r_durability == 0)
    {
      result = true;
    }
    else
    {
      result = false;
    }

    return result;
  }


  Robot& Robot::operator-=(int durability){
    r_durability -= durability;
    if (r_durability < 1)
    {
      r_durability = 0;
    }
    return *this;
  }

  int Robot::getDurability(){
    return r_durability;
  }

  void box(Robot& firstRobot, Robot& secondRobot){
    cout << "Attempting to begin a Robot boxing match" << endl;
    if (firstRobot.isEmpty() || secondRobot.isEmpty()){
      cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
    }
    else{
      cout << "Both participants are operational... beginning the bout" << endl;
      while (!firstRobot && !secondRobot){
        if (firstRobot.getLegs() > secondRobot.getLegs()){
          secondRobot -= firstRobot.getArms().getForce();
          if (!secondRobot){
            firstRobot -= secondRobot.getArms().getForce();
          }
        }
        else{
          firstRobot -= secondRobot.getArms().getForce();
          if (!firstRobot){
            secondRobot -= firstRobot.getArms().getForce();
          }
        }
      }

      cout << "The bout has concluded... the winner is: " << endl;
      if (!firstRobot){
        firstRobot.display();
      }
      else{
        secondRobot.display();
      }
    }
  }
}
