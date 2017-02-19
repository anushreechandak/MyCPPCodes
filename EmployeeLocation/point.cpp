// Filename: point.cpp
// Description: contains implementation of the member functions and data members of point class
// Author: Anushree Chandak

//include header files
#include "point.h"
#include<iostream>


point::point()// default construcor
{
	X=0;// initialize X to zero
	Y=0;//initialize Y to zero
}
point::point(int x,int y)// copy constructor
{
	X=x;// Intialize X to given x point
	Y=y;// Intialize Y to given y point
}

void point::setX(int xvalue)// set function for X point
{
	X=xvalue;//set X to given xvalue
}

int point::getX()// function returns X value
{
	return X;// return X
}

void point::setY(int yvalue)// set function for Y point
{
	Y=yvalue;//set Y to given yvalue
}

int point::getY()// function returns Y value
{
	return Y; //return Y
}

