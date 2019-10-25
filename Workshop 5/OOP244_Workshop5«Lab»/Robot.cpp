// Robot.cpp
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

  Robot::Robot(const char* nickName, int armsForce, int robotDurability){
   if (nickName == nullptr || strcmp(nickName, "") == 0)
    {
      safeEmptyState();
    }
    else
    {
      strcpy(r_nickname, "");
      if (strlen(nickName) > NICK_MAX_LEN)
      {
        for (int i = 0; i < NICK_MAX_LEN; i++)
        {
          r_nickname[i] = nickName[i];
        }
      }
      else
      {
        strcpy(r_nickname, nickName);
      }
      
      if (robotDurability < 1)
      {
        r_durability = 100;
      }
      else
      {
        r_durability = robotDurability;
      }

      Arms a{ armsForce };
      r_arms += a.getForce();
    }
  }
  bool Robot::isEmpty() const{
    return strcmp(r_nickname, "") == 0 && r_durability == 0 && r_arms.isEmpty();
  }

  ostream& Robot::display() const{
    if (isEmpty()){
      cout << "This Robot isn't operational" << endl;
    }
    else{
      cout << "***Robot Summary***" << endl;
      cout << "Nickname: " << r_nickname << endl;
      cout << "Arm Power: " << r_arms.getForce() << endl;
      cout << "Durability: " << r_durability << endl;
    }
        return cout;
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
}
