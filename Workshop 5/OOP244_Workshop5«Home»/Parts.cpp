// Parts.cpp
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
This file contains all of the functions and operators definition related to parts of
the robot.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Parts.h"
#include <iostream>

using namespace std;
namespace sdds{
  Arms::Arms(){
    AllocateMemoryForForce();
  }

  void Arms::AllocateMemoryForForce(){
    // if ( val != 0){
       a_force = 0;
     //} else{
    //  a_force = MIN_FORCE;
    // }
  }

  Arms::Arms(int armsForce){
    if (armsForce < 1){
      a_force = MIN_FORCE;
    }
    else{
      a_force = armsForce;
    }
  }
  bool Arms::isEmpty() const{
    return a_force == 0;
  }

  int Arms::getForce() const{
    return a_force;
  }

  Arms& Arms::operator++(){
    
    a_force += 10;
    return *this;
  }

  Arms Arms::operator++(int){
    Arms a = *this;
    a_force += 10;
    return a;
  }

  Arms& Arms::operator+=(int add){
    a_force += add;
    if (a_force < 1)
    {
      a_force = 0;
    }
    return *this;
  }

  Legs::Legs(){
    AllocateMemoryForSpeed(0);
  }

  void Legs::AllocateMemoryForSpeed(int val){
    l_speed = val;
  }


  Legs::Legs(int legsSpeed){
    if (legsSpeed < 1){
      l_speed = MIN_SPEED;
    }
    else{
      l_speed = legsSpeed;
    }
  }

  int Legs::getSpeed() const{
    return l_speed;
  }
  bool Legs::isEmpty() const{
    return l_speed == 0;
  }

  Legs& Legs::operator-=(int PassedInt){
    l_speed -= PassedInt;

    if (l_speed < 1){
      l_speed = 0;
    }

    return *this;
  }

  bool operator>(const Legs& firstSet, const Legs& secondSet){
    if (firstSet.getSpeed() > secondSet.getSpeed()){
      return true;
    }

    else {
      return false;
    }
  }

  bool operator<(const Legs& firstSet, const Legs& secondSet){
    if (!(firstSet > secondSet)){
      return true;
    }
    else{
      return false;
    }
  }

  bool operator>(const Arms& firstSet, const Arms& secondSet){
    if (firstSet.getForce() > secondSet.getForce()){
      return true;
    }
    else {
      return false;
    }
  }

  bool operator<(const Arms& firstSet, const Arms& secondSet){
    if (!(firstSet > secondSet)){
      return true;
    }
    else{
      return false;
    }
  }
}

