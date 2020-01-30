/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 30/01/2020

Question-
On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have another 

bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count the number 

of pairs of bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)

You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.

*/

#include"stdafx.h"
#include<iostream>
#include<vector>
#include<utility>

// Uncomment if you want ot print some important variables.
//#define DEBUG	

using namespace std;

// The below method calculate and tells whether the slope between two points is a whole number or not.
bool isSlopeWholeNumber(const pair<int,int> &bloc1, const pair<int,int> &bloc2) {
	bool retVal = false;
	int numerator = abs(bloc2.second - bloc1.second);
	int denominator = abs(bloc2.first - bloc1.first);
	// If my numberator would be equal to denominator, than it means my other bishop is present in a straight line to another bishop.
	if (numerator == denominator) {
		retVal = true;
	}
	return retVal;
}

int computeAllBishopsAttack(const vector<pair<int,int>> &bishopLoc) {
	int retVal = 0;
	if (bishopLoc.empty()) {
		return retVal;
	}

	int indexUpper = bishopLoc.size();
	for (int i = 0;i < indexUpper;++i) {
		if (i == indexUpper - 1) {
			// need to break the loop as j will go out of bound. Need not check the condition of whole number slope for last element.
			break;
		}
		for (int j = i + 1;j < indexUpper;++j) {
			if (isSlopeWholeNumber(bishopLoc[i], bishopLoc[j])) {
				++retVal;
			}
		}
	}
	return retVal;
}

int main(int argc, char *Argv[]) {
	// the following vector contains the locations of bishop.
	vector<pair<int, int>> bishopLoc;
	bishopLoc.push_back(make_pair(0, 0));
	bishopLoc.push_back(make_pair(1, 2));
	bishopLoc.push_back(make_pair(2, 2));
	bishopLoc.push_back(make_pair(4,0));
	computeAllBishopsAttack(bishopLoc);
#ifdef DEBUG
	cout << computeAllBishopsAttack(bishopLoc);
	getchar();
#endif // DEBUG
	
	return 0;
}
