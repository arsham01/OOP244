#ifndef SDDS_PARKINGSPOT_H
#define SDDS_PARKINGSPOT_H

namespace sdds {
	struct ParkingSpot {
		char plate[9];
		char* car;
	};
	void setEmpty(ParkingSpot&);
	bool isEmpty(const ParkingSpot&);
	void freeSpot(ParkingSpot&);
	void print(const ParkingSpot&);
	void parkCar(ParkingSpot&);
}

#endif