#include <iostream>
#include <cstring>
#include "utils.h"
#include "ParkingSpot.h"

using namespace std;
namespace sdds{
  void setEmpty(ParkingSpot& Pspot){
    Pspot.plate[0] = '\0';
    Pspot.car = nullptr;
  }

  bool isEmpty(const ParkingSpot& Pspot){ 
    return (Pspot.car == nullptr);
  }

  void freeSpot(ParkingSpot& Pspot){
    delete[] Pspot.car;
    setEmpty(Pspot);
  }

  void print(const ParkingSpot& Pspot){
    cout << Pspot.car << ", plate number: " << Pspot.plate << endl;
  }

  void parkCar(ParkingSpot& Pspot){
    cout << "Make and Model: ";
    char modelOfCar[61] = "\0";

    read(modelOfCar, 60,"Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
    int size = strlen(modelOfCar);
    Pspot.car = new char[size +1];
    strcpy(Pspot.car,modelOfCar);
    cout << "License Plate: ";
    read(Pspot.plate, 8,"Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");
  }
}