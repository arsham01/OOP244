#ifndef SDDS_PARKINGLOT_H
#define SDDS_PARKINGLOT_H
#include "ParkingSpot.h"

namespace sdds{

  struct ParkingLot{
    int NoOfTheSpots;
    ParkingSpot* pSpots;
  };

  void setEmpty(ParkingLot&);
  bool isEmpty(const ParkingLot&);
  void openParking(ParkingLot&, int noOfSpots);
  int parkCar(ParkingLot&);
  bool returnCar(ParkingLot&, int spotNo);
  void closeParking(ParkingLot&);
}
#endif