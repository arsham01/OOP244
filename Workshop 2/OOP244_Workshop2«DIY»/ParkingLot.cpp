#include <iostream>
#include <cstring>
#include "utils.h"
#include "ParkingLot.h"

using namespace std;
namespace sdds {
  void setEmpty(ParkingLot& Plot) {
    Plot.NoOfTheSpots = 0;
    Plot.pSpots = nullptr;
  }

  bool isEmpty(const ParkingLot& Plot){
    return (Plot.pSpots == nullptr);
  }

  void openParking(ParkingLot& Plot, int noOfSpots){
    Plot.NoOfTheSpots = noOfSpots;
    Plot.pSpots = new ParkingSpot[noOfSpots];
    int i;
    for (i = 0; i < noOfSpots ; i++){
      setEmpty(Plot.pSpots[i]);
    }
  }

  int parkCar(ParkingLot& Plot){
    int i;
    for (i = 0; i < Plot.NoOfTheSpots ; i++){
      if(isEmpty(Plot.pSpots[i])){
        parkCar(Plot.pSpots[i]);
        return i;
      }
    }
    return -1;
  }

  bool returnCar(ParkingLot& Plot, int spotNo){
    if (spotNo >= 0 && spotNo <= Plot.NoOfTheSpots && !isEmpty(Plot.pSpots[spotNo]) ){
      cout << "Returning ";
      print(Plot.pSpots[spotNo]);
      freeSpot(Plot.pSpots[spotNo]);
      return true;
    }
    else 
    return false;
  }
  void closeParking(ParkingLot& Plot){
    int i ;
    for (i = 0; i < Plot.NoOfTheSpots; i++)
    {
        if (!isEmpty(Plot.pSpots[i]))
				returnCar(Plot, i);
    }
     delete[] Plot.pSpots;
    setEmpty(Plot);   
    }
}