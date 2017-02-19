// Filename: EmployeeLoc.cpp
// Description: conatins main function that takes employee's name and coordinates as input from user 
               // and uses that information to provide employee's location
// Author: Anushree Chandak
#include "location.h"// include location class
#include<iostream>
#include<vector>
#include"point.h"// include point class
#include"employee.h"//include employee class
#include<string>
using namespace std;

void main()
{
	string name; // variable to store name of employee
	int X=0;// X coordinate
	int Y=0;// Y coordinate
	location loc; //call default constructor of location class
	while(X!=-1)
	{
	cout<<"\nEnter Employee Name: ";// get the employee's name
	cin>>name;
	cout<<"Enter X position(-1 to quit):";// get his X coordinate
	cin>>X;
	if(X==-1) // if user enters -1 exit from program
		break;
	cout<<"Enter Y position(-1 to quit):";// get his Y coordinate
	cin>>Y;
	if(Y==-1) // if user enters -1 exit from program
		break;

	point p1(X,Y);// call copy constructor of point class
	employee E(name,X,Y);// call copy constructor of employee class
	
	//check what getlocation function of location class returns based on the X,Y coordinate provided by user
	if(loc.getlocation(p1)==loc.NEWYORK) 
		cout<<"\n"<<E.getName(name)<<" is in NEW YORK city"<<endl;
	else if(loc.getlocation(p1)==loc.SANFRANSISCO)
		cout<<"\n"<<E.getName(name)<<" is in SAN FRANSISCO"<<endl;
	else if(loc.getlocation(p1)==loc.LOSANGELES)
		cout<<"\n"<<E.getName(name)<<" is in LOS ANGELES"<<endl;
	else if(loc.getlocation(p1)==loc.CHICAGO)
		cout<<"\n"<<E.getName(name)<<" is in CHICAGO"<<endl;
	else if(loc.getlocation(p1)==loc.NOT_FOUND)
		cout<<"\n"<<E.getName(name)<<"'s Location NOT FOUND"<<endl;
	}
	

}

