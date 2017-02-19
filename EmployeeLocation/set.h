// Filename: set.h
// Description: contains declaration of the member functions and data members of set class
// Author: Anushree Chandak

//include header files
#ifndef SET
#define SET
#pragma once
#include<vector>
using namespace std;
class set
{
public:
	set(); // default constructor

	set(vector<bool> &vect); // constructor intializing the vector
	
	void copyvector(vector<bool>&vect);

	bool isMember(int); // validating if element in the vector is true or not

	set Union(set &s); // returns union of two sets

	set Intersection(set &s); // returns intersection of two sets

	void print (); // prints the variable

	
private:
	vector<bool> v;// boolean vector 
};

#endif