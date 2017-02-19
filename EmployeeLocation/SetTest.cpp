// Filename: SetTest.cpp
// Description: contains main function that tests all public memeber functions
               //of set class if they are working properly
// Author: Anushree Chandak

//include header files

#include"set.h"
#include<iostream>
#include<vector>
using namespace std;

// function that resets the boolean vector to 0
vector<bool> reset(vector<bool> &v)
{
	for(int i=0;i<v.size();i++)
	{
		v[i]=0;
	}
	return v;
}

//main function
void main()
{
	set set1,set2,set3,set4,set5;// objects of set class
	vector<bool> temp (10);// boolean vector
	//TEST UNION FUNCTION
	cout<<"TESTING UNION FUNCTION"<<endl;
	// creat set1 vector whose 2,3,7,8 values are true
	temp[2]=true;
	temp[3]=true;
	temp[7]=true;
	temp[8]=true;

	set1.copyvector(temp);
	// print the set
	cout<<"set 1 is : ";
	set1.print(); 
	reset(temp); // reset the vector

	// creat set2 vector whose 4,5,6,7,8 values are true
	for(int i=4;i<8;i++)
	{
		temp[i]=true;
	}
	set2.copyvector(temp);
	// print the set
	cout<<"\nset 2 is : "; 
	set2.print();
	reset(temp);//reset vector
	set un=set1.Union(set2);// get the union of 2 sets
	cout<<"\nUnion of 2 sets is: ";// print union of 2 sets
	un.print();

	//TEST INTERSECTION FUNCTION
	cout<<"\n\nTESTING INTERSECTION FUNCTION"<<endl;
	// creat set whose 2,3,4 values are true
	temp[2]=true;
	temp[3]=true;
	temp[4]=true;
    set3.copyvector(temp);
	//print set
	cout<<"set 1 is : "; 
	set3.print();
	reset(temp);// reset vector
	//creat vector whhose 2 value is true
	temp[2]=true;
	set4.copyvector(temp);
	//print the vector
	cout<<"\nset 2 is : "; 
	set4.print();
	reset(temp);//reset temp
    set inter=set3.Intersection(set4);// get the intersection of 2 neew sets
	cout<<"\nIntersection of 2 sets is: ";
	inter.print();//print that intersection result
	cout<<endl;

    //TEST isMember FUNCTION
	cout<<"\nTESTING isMember FUNCTION"<<endl;
	//creat vector whose value at 4 and 8 position is true
	temp[4]=true;
	temp[8]=true;
	set5.copyvector(temp);
	cout<<"The position which hold true value are 4 and 8"<<endl;
	cout<<"After using the IsMember function position which hold true values are:";
	//check isMember function if it gives true values at postion at 4 and 8
	for(int i=0;i<10;i++)
	{
		if(set5.isMember(i))
			cout<<i<<" ";// print the vector using isMember function.
	}
	cout<<endl;
}