// Parts.cpp
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
}

