// Filename: point.h
// Description: contains declaration of the member functions and data members of point class
// Author: Anushree Chandak

//include header files
#ifndef POINT
#define POINT
#pragma once
class point
{
public:
	point();// default constructor
	point(int,int);//copy constructor 
	void setX(int);// set function for X point
	int getX();// get function
	void setY(int);// set function for Y point
	int getY();// get function
private:
	int X;//X variable
	int Y;//Y variable
	
};
#endif
