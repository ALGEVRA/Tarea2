// =================================================================
//
// File: main.cpp
// Author: Francisco Alejandro Vel[azquez Ledesma]
// Date: 03/09/22
//
// =================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {

  ifstream inputFile;
	ofstream outputFile;

	int N1, P;

	inputFile.open(argv[1]);
	outputFile.open(argv[2]);

	inputFile >> N1;
	vector<int>vectorN(N1);
	for(int n = 0; n < N1; n++) {
		inputFile >> vectorN[n];
	}
	
	vector<int> vector1 = vectorN;
	vector<int> vector2 = vectorN;

	int iS = insertionSort(vector1);
	int bS = bubbleSort(vector2);
	int sS = selectionSort(vectorN);

	outputFile << bS << " " << sS << " " << iS << endl << endl;

	inputFile >>  P;
	pair<int,int> sS_1;
	pair<int,int> bS_1;

	int d;

	for(int p = 0; p < P; p++) {
		inputFile >> d;
		sS_1 = sequentialSearch(vectorN, d);
		outputFile << sS_1.first << ' ' << sS_1.second << ' ';
		bS_1 = binarySearch(vectorN, d);
		outputFile << bS_1.second << endl;
	}
  
	inputFile.close();
	outputFile.close();

	return 0;
}
