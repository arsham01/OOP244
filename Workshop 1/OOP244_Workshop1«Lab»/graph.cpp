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


#include <iostream>
#include <iomanip>
#include "tools.h"
#include "graph.h"
using namespace std;


void printGraph(int samples[], int noOfSamples){
  int max = findMax(samples, noOfSamples);
  line(GRAPH_WIDTH + 10, " Graph ");
  for (int i = 0; i < noOfSamples; i++){
    printBar(samples[i], max);
  }
  line(GRAPH_WIDTH + 10);
}
// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max){
  int i;
  int barlength = GRAPH_WIDTH * val / max;
  cout << "| ";
  for (i = 0; i < barlength; i++){
    cout << "*";
  }
  cout << " " << setw(GRAPH_WIDTH + 6 - barlength) << setiosflags(ios::left) << val << "|" << endl;
}

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples){
  int i;
  for (i = 0; i < noOfSamples; i++){
     line(28);
     cout << "\\ " << (i + 1) << "/" << setw(2) << setiosflags(ios::left) << noOfSamples << ":                    /";
     goBack(20);
     samples[i] = getInt(1, 1000000);
  }
}

// finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
// otherwise it will return GRAPH_WIDTH. 
int findMax(int samples[], int noOfSamples){
  int max = samples[0];
  int i;
  for (i = 1; i < noOfSamples; i++){
    if (max < samples[i]) max = samples[i];
  }
  return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
}

