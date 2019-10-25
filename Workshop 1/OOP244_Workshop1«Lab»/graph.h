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

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20
#define GRAPH_WIDTH 65

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);

// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);

// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);

// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);
