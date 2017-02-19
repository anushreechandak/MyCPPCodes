// Filename: employee.h
// Description: contains declaration of the member functions and data members of employee class
// Author: Anushree Chandak

//include header files
#ifndef EMP
#define EMP
#pragma once
#include<string>
#include"point.h"// include point class
using namespace std;
class employee
{
public:
	employee();// default costructor
	employee(string,int,int);//copy constructor
	void setCoordinates(point & Point);// set function for coordinate
	int getCoordinates();// get coordinates
	void setName(string & name);// set name for employee
	string getName(string & name);// get name of the employee
private:
	string name;// name of employee
	point myPoint;
	
};
#endif
