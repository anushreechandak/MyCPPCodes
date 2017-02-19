// Filename: location.h
// Description: contains declaration of the member functions and data members of location class
// Author: Anushree Chandak
#ifndef LOC
#define LOC
#pragma once
#include<iostream>
#include<vector>
#include"point.h"// include point class
#include"set.h"// include set class
using namespace std;
class location
{
public:
	location();// default constructor
	enum LOCATION{NOT_FOUND,NEWYORK,SANFRANSISCO,LOSANGELES,CHICAGO};//enum
	LOCATION getlocation(point &p);// get location of employee
private:
	set newyorkx;// set for X coordinate for NewYork 
	set newyorky;// set for Y coordinate for NewYork 
	set sanfransiscox;// set for X coordinate for Sanfransisco
	set sanfransiscoy;// set for Y coordinate for Sanfransisco
	set losangelesx;// set for X coordinate for Losangeles
	set losangelesy;// set for Y coordinate for Losangeles
	set chicagox;// set for X coordinate for chicago
	set chicagoy;// set for Y coordinate for chicago
};

#endif