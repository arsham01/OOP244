/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	w1_in_lab.cpp
// Version 1.0
// Date	2019/09/02
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name  Arsham Yaghoobi          Date  Sep-10-2019          Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/

//Functions prototypes

int getInt(int min, int max);
// moves the cursor backwards
void goBack(int n);
// displays the user interface menu
int menu(int noOfSamples);
// Draws a line and adds a label if provided
void line(int n, const char* label = nullptr); 

