// Filename: set.cpp
// Description: contains implementation of the member functions and data members of set class
// Author: Anushree Chandak

//include header files
#include "set.h"
#include<iostream>
#include<vector>
using namespace std;

set::set() // default constructor
{
}

set::set(vector<bool> &vect) // constuctor intializing the set with given vector
{
	v=vect;
}

void set::copyvector(vector<bool> &vect)// function that copies the given vector to the private vector 
{
	v=vect;
}
bool set::isMember(int x) // checking if element in the vector true or not
{
	if (v[x]==true)// if value of the element is true then return true else return false
		return true;
	else
		return false;
}
// function that returns union of the two sets
set set::Union(set &s)
{
	//two boolean variables
	bool x;
	bool y;
	for(int i=0;i<10;i++)
	{
		x=isMember(i);// check if member of our set is true or false
		y=s.isMember(i);// check if the members of given set is true or not
		if (x==true || y==true)// if any of the member is true then return true or else false 
			v[i]=true;
		else
			v[i]=false;
	}
    return v; // return the vector
}
// function that returns intersection of two sets
set set::Intersection(set &s)
{
	// two boolean variables
	bool x;
	bool y;
	for(int i=0;i<10;i++)
	{
		x=isMember(i);//check if member of our set is true
		y=s.isMember(i);// check if member of the given set is true
		if(x && y==true) // if both are true then only return true
			v[i]=true;
		else if(x && y == false)// if both members are fals ethen return false
			v[i]=false;
	}
	return v;
}
void set::print()// function that prints the number of the member of the vector which are true
{
	for(int i=0;i<v.size();i++)
	{
		if(isMember(i))//when member of vector is true then print the number of that member
			cout<<i<<" ";
	}
}