#ifndef SDDS_FLOWER_H
#define SDDS_FLOWER_H
#include <iostream>
#define SDDS_DEBUG__
namespace  sdds {

  const int NAME_MAX_LEN = 25;
  const int COL_MAX_LEN = 15;


  class Flower {
    char* f_name;
    char* f_colour;
    double f_price;

    public :

      Flower();
      Flower(const char* name, const char* colour,double price);
      ~Flower();
      void AllocateSizeOfName(const char* str);
      void AllocateSizeOfColour(const char* str);
      const char* name() const;
      const char* colour() const;
      double price() const;
      bool isEmpty()const;
      void setEmpty();
      void setName(const char* prompt); 
      void setColour(const char* prompt); 
      void setPrice(const char* prompt);
      void setFlower();  
      std::ostream& display() const; 
  };

  
} 



#endif