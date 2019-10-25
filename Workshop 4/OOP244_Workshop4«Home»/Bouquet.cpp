#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bouquet.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds{
  Bouquet::Bouquet() {
    b_price = 0.0;
    AllocateSizeOfMessage("");
    b_flowerCount = 0;
    b_flowers = 0;
  }
  
  void Bouquet::AllocateSizeOfMessage(const char* str){
    int size = strlen(str);
      b_message = new char[size +1];
      strcpy(b_message, str);
  }

  Bouquet::Bouquet(const Flower* flower, int noOfFlowers, const char* message){
    b_price = 0.0;
    if (flower == nullptr)
    {
      setEmpty();
    }
    else
    {
      if (noOfFlowers <= MAX_FLOWERS)
      {
        b_flowerCount = noOfFlowers;
      }
      else if (noOfFlowers > MAX_FLOWERS)
      {
        b_flowerCount = MAX_FLOWERS;
      }

      b_flowers = new Flower[b_flowerCount];
      for (int i = 0; i < b_flowerCount; i++)
      {
        b_flowers[i].setName(flower[i].name(), 1);
        b_flowers[i].setColour(flower[i].colour(), 1);
        b_flowers[i].setPrice(flower[i].price(), 1);
      }

      for (int i = 0; i < b_flowerCount; i++)
      {
        b_price += b_flowers[i].price();
      }
      b_message = new char[strlen(message) + 1];
      strcpy(b_message, message);
    }
    
  }

  Bouquet::~Bouquet(){
    if (isEmpty()){
      cout << "An unknown bouquet has departed..." << endl;
    }
    else{
      cout << "A bouquet has departed with the following flowers..." << endl;
      delete[] b_flowers;
      delete[] b_message;
    }
  }

  

  const char* Bouquet::message() const {
    return b_message;
  }

  double Bouquet::price() const{
    return b_price;
  }

  bool Bouquet::isEmpty()const{
    return  (b_flowerCount == 0 || b_flowers == 0 || b_price == 0.0 || b_message == nullptr);
  }


  void Bouquet::setEmpty(){
    b_price = 0.0;
    AllocateSizeOfMessage("");
    b_flowerCount = 0;
    b_flowers = 0;
  }

  void Bouquet::setMessage(const char* prompt){
    cout << prompt;
    char message[31] = "\0";
    read(message, 30, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
    AllocateSizeOfMessage(message);
  }


  void Bouquet::discardBouquet(){
    cout << "Discarding the current bouquet..." << endl;
    delete[] b_message;
    delete[] b_flowers;
    setEmpty();
    
  }

  void Bouquet::arrangeBouquet(){
    char option [2] = {'0'};
    cout << "Arranging a new bouquet..." << endl;
    if (!isEmpty()) {
      cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
      read(option, 1, "The decision is either Y or N... Try again: ");

      if (strcmp(option, "Y") == 0){
        discardBouquet();
      }
      else if (strcmp(option, "N") == 0){
        cout << "No new arrangement performed..." << endl;
      }
    }

    if (strcmp(option, "Y") == 0 || isEmpty()){
      cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
      read(b_flowerCount, 1, 3, "The valid range is 1-3... Try again: ");
      b_flowers = new Flower[b_flowerCount];
      double total = 0;
      for (int i = 0; i < b_flowerCount; i++) {
        b_flowers[i].setFlower();
        cin.clear();
        while (cin.get() != '\n');
        total += b_flowers[i].price();
      }
      b_price = total;
      cout << "A bouquet has been arranged..." << endl;
      setMessage("Enter a message to send with the bouquet...: ");
    } 
  }
  

  ostream& Bouquet::display() const{
    if (isEmpty()){
      cout << "This is an empty bouquet..." << endl;
    }
    else {
      cout << "This bouquet worth ";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout << b_price << " has the following flowers..." << endl;
      for (int i =0 ; i < b_flowerCount ; i++){
        cout << "Flower: " << b_flowers[i].colour() << " " << b_flowers[i].name() << " Price: " << b_flowers[i].price() << endl;


      }
      cout << "with a message of: " << b_message ;
      cout << endl;
    }
    
    return cout;
  }

}