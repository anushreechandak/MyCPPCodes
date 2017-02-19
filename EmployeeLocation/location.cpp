// Filename: location.cpp
// Description: contains implementation of the member functions and data members of location class
// Author: Anushree Chandak
#include "location.h"
#include<iostream>
#include<vector>
#include"point.h"//include point class
#include"set.h"//include set class
using namespace std;

location::location(void)
{
	//define 4 boolean vector each for 1 city
	vector<bool>ny(21);
	vector<bool>sf(21);
	vector<bool>la(21);
	vector<bool>ch(21);

	//initilaise vector ny to TRUE from 0-5
	for(int i=0;i<6;i++)
		ny[i]=true;
	newyorkx.copyvector(ny);// coordinate SETS for newyork are set to TRUE for values 0-5
	newyorky.copyvector(ny);

	//initilaise vector sf to TRUE from 6-10
	for(int i=6;i<11;i++)
		sf[i]=true;
	sanfransiscox.copyvector(sf);// coordinate SETS for sanfransisco are set to TRUE for values 6-10
	sanfransiscoy.copyvector(sf);

	//initilaise vector la to TRUE from 11-15
	for(int i=11;i<16;i++)
		la[i]=true;
	losangelesx.copyvector(la);// coordinate SETS for losangeles are set to TRUE for values 11-16
	losangelesy.copyvector(la);

	//initilaise vector ch to TRUE from 16-21
	for(int i=16;i<21;i++)
		ch[i]=true;
	chicagox.copyvector(ch);// coordinate SETS for chicago are set to TRUE for values 16-21
	chicagoy.copyvector(ch);

}
// function that returns location of employee based on the coordinates passed
location::LOCATION location::getlocation(point &p)
{
	int X=p.getX();//get X coordinate
	int Y=p.getY();//get Y coordinate

	if(newyorkx.isMember(X) && newyorky.isMember(Y))//if coordinates lie between 0-5 return NEWYORK
	{
		return NEWYORK;
	}
	else if(sanfransiscox.isMember(X) && sanfransiscoy.isMember(Y))//if coordinates lie between 6-10 return SANFRANSISCO
	{
		return SANFRANSISCO;
	}
	else if (losangelesx.isMember(X) && losangelesy.isMember(Y))//if coordinates lie between 11-16 return LOSANGELES
	{
		return LOSANGELES;
	}
	else if(chicagox.isMember(X) && chicagoy.isMember(Y))//if coordinates lie between 16-21 return CHICAGO
	{
		return CHICAGO;
	}
	else//else return location NOT_FOUND
	{
		return NOT_FOUND;
	}
}

