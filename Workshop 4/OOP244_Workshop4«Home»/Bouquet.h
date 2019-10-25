#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H
#include <iostream>
#include "Flower.h"
#include "utils.h"
namespace  sdds {
  const int MESS_MAX_LEN = 25;
  const int MAX_FLOWERS = 3;

  class Bouquet {
    double b_price;
    char* b_message;
    Flower* b_flowers;
    int b_flowerCount;

    public:
    Bouquet();
    Bouquet(const Flower* flower, int noOfFlowers, const char* message = "Congratulations");
    ~Bouquet();
    void AllocateSizeOfMessage(const char* str);
    const char* message() const;
    double price() const;
    bool isEmpty()const;
    void setEmpty();
    void setMessage(const char* prompt);
    void discardBouquet();
    void arrangeBouquet();
    std::ostream& display() const;
  };
}
#endif