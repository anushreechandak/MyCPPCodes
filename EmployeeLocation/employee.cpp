// Filename: employee.cpp
// Description: contains implementation of the member functions and data members of employee class
// Author: Anushree Chandak

//include header files
#include<iostream>
#include "employee.h"
#include<string>
#include"point.h"// include point class
using namespace std;

employee::employee(void)//empty default constructor
{
}
employee::employee(string nameofemp,int x,int y)//copy constructor
{
	name=nameofemp;//intialize name
	myPoint.setX(x);// initialize X coordinate
	myPoint.setY(y);//initialize Y coordinate
}

int employee::getCoordinates()// get coordinates
{
	return myPoint.getX();// return X coordinate
	return myPoint.getY();// return Y coordinate
}
void employee::setCoordinates(point &p)// set coordinates
{
	myPoint.setX(p.getX());// set X coordinate
	myPoint.setY(p.getY());//set Y coordinate
}

void employee::setName(string &nameofemp)// set name of employee
{
	name=nameofemp;// set name
}
string employee::getName(string &nameofemp)// get anme of employee
{
	return name;// return name
}