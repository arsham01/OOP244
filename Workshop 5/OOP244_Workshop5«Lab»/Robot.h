// Robot.h
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


    public:

    Robot();
    void AllocateMemoryForNickName();
    void AllocateMemoryForDurability();
    void safeEmptyState();
    bool isEmpty() const;
    Robot(const char* nickName, int armsForce, int robotDurability);
    std::ostream& display() const;
    operator bool() const;
  };
}

#endif