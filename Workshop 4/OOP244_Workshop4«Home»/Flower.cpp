#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Flower.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds{

  Flower::Flower() {
    AllocateSizeOfName("");
    AllocateSizeOfColour("");
    f_price = 0;
    }
  void Flower::AllocateSizeOfName(const char* str) {
      int size = strlen(str);
      f_name = new char[size +1];
      strcpy(f_name, str);
    }
  void Flower::AllocateSizeOfColour(const char* str){
    int size = strlen(str);
    f_colour = new char[size +1];
    strcpy(f_colour, str);
  } 


  Flower::Flower(const char* name, const char* colour,double price){
    /*AllocateSizeOfName(name);
    if (name == nullptr || name[0] == '\0'){
      AllocateSizeOfName("");
    }
    AllocateSizeOfColour(colour);
    if (colour == nullptr || colour[0] == '\0'){
      AllocateSizeOfColour("");
    }
    f_price = price;
    if (price <= 0){
      f_price = 0;
    }*/
    if (name == nullptr || name[0] == '\0')
			setEmpty();
		else if (colour == nullptr || colour[0] == '\0')
			setEmpty();
		else if (price <= 0)
			setEmpty();
		else {
      AllocateSizeOfName(name);
      AllocateSizeOfColour(colour);
      f_price = price;
    }
  }

    Flower::~Flower() {
		if (isEmpty())
			cout << "An unknown flower has departed..." << endl;
		else
			cout << f_colour << " " << f_name << " has departed..." << endl;

		delete[] f_name;
		delete[] f_colour;
	  }

  

  const char* Flower::name() const{
    return f_name;
  }


  const char* Flower::colour() const{
    return f_colour;
  }

  double Flower::price() const{
    return f_price;
  }

  bool Flower::isEmpty()const{
    return (f_name == nullptr || f_name[0] == '\0' || f_colour == nullptr || f_colour[0] == '\0' || f_price <= 0);
  }

  void Flower::setEmpty(){
    AllocateSizeOfColour("");
    AllocateSizeOfName("");
    f_price = 0;
  }

  void Flower::setName(const char* prompt){
    cout << prompt;
    char flowerName[26] = "\0";
    read(flowerName, 25, "A flower's name is limited to 25 characters... Try again: ");
    AllocateSizeOfName(flowerName);
  }

  void Flower::setColour(const char* prompt){
    cout << prompt;
    char flowerColour[16] = "\0";
    read(flowerColour, 15, "A flower's colour is limited to 15 characters... Try again: ");
    AllocateSizeOfColour(flowerColour);
  }

  void Flower::setPrice(const char* prompt){
    cout << prompt;
    cin >> f_price;
    while ( f_price <= 0){
      cout << "A flower's price is a non-negative number... Try again: ";
      cin.clear();
      cin >> f_price;
    }
    
  }

  void Flower::setFlower(){
    cout << "Beginning the birth of a new flower..." << endl;
		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");
		cout << "The flower's current details..."<<endl;
		display();
  }

  ostream& Flower::display() const{
    if (isEmpty())
			return  cout << "This is an empty flower..." << endl;
		else
		{
			return cout << "Flower: " << Flower::colour() << " " << Flower::name() << " Price: " << Flower::price() << endl;
		}

	
  }

  void Flower::setName(const char* name, int len){
    AllocateSizeOfName(name);
    len = strlen(name);
  }

  void Flower::setColour(const char* colour, int len){
    AllocateSizeOfColour(colour);
    len = strlen(colour);
  }

  void Flower::setPrice(double price, int len){
    f_price = price;
    if (price < 0){
      price = 1;
      f_price = price;
    }
  }

}
