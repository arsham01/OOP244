// RobotSquad.cpp
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
the robot squad.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "RobotSquad.h"

using namespace std;
namespace sdds {
  RobotSquad::RobotSquad(){
    setEmpty();
  }
  void RobotSquad::AllocateMemoryForName(const char* str){
   strcpy(rs_name, str);
  }
  void RobotSquad::AllocateMemoryForRoster(){
    rs_robotRoster = nullptr;
  }
  void RobotSquad::AllocateMemoryForRosterCount(){
    rs_robotRosterCount = 0;
  }
  void RobotSquad::setEmpty(){
    AllocateMemoryForName("No Name");
    AllocateMemoryForRoster();
    AllocateMemoryForRosterCount();
  }

  RobotSquad::RobotSquad(const char* str){
    strcpy(rs_name,str);
    AllocateMemoryForRoster();
    AllocateMemoryForRosterCount();
    
  }

  RobotSquad::~RobotSquad() {
		delete[] rs_robotRoster;
    rs_robotRoster = nullptr;
	}
  bool RobotSquad::isEmpty() const { 
    return rs_robotRosterCount == 0;
  }

 


	Robot* RobotSquad::getRoster()const{
    return rs_robotRoster;
  }

  ostream& RobotSquad::display() const{
    if (isEmpty()){
      cout << "Squad **" << rs_name << "** has no members" << endl;
    }
    else {
      cout << "***Squad Summary***" << endl;
			cout << "Name: " << rs_name << endl;
			cout << "Roster Count: " << rs_robotRosterCount << endl;
			cout << "Roster:" << endl;
			for (int i = 0; i < rs_robotRosterCount; i++) {
				rs_robotRoster[i].display();
			}
    }
    return cout;
  }



  RobotSquad& RobotSquad::operator+=(Robot robot){
    int i;
    Robot* save;
    save = nullptr;
    save = new Robot[rs_robotRosterCount];
    for (i = 0; i < rs_robotRosterCount; i++)
    {
       save[i] = this->rs_robotRoster[i];
    }
    delete[] this->rs_robotRoster;
    this->rs_robotRoster = nullptr;
    this->rs_robotRoster = new Robot[++rs_robotRosterCount];
    for (i = 0; i < rs_robotRosterCount - 1; i++)
    {
      this->rs_robotRoster[i] = save[i];
    }
    delete[] save;
    this->rs_robotRoster[i] = robot;
    return *this;
  }
  

  RobotSquad& RobotSquad::operator--(){
    if (isEmpty()){
      cout << "This squad **"<< rs_name <<"** has no members or is uninitialized. Can't do --." << endl;
    }
    else if(rs_robotRosterCount == 1){
      delete[] rs_robotRoster;
      setEmpty();
    }
    else {
      Robot* save;
      save = nullptr;
      save = new Robot[rs_robotRosterCount - 1];
      for (int i = 0; i < rs_robotRosterCount - 1; i++){
          save[i] = rs_robotRoster[i];
      }
      delete[] rs_robotRoster;
      rs_robotRoster = nullptr;
      rs_robotRoster = new Robot[--rs_robotRosterCount];
      for (int i = 0; i < rs_robotRosterCount; i++){
        rs_robotRoster[i] = save[i];
      }
      delete[] save;
    }
    return *this;
  }
}