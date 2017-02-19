//Filename: main.cpp
// Description: This file is the main function where we call the selctionsort class functions 
//              to perform different operations .
//              also,we have some templates and other helper function declared outside main function
//              to manage the arrays and the vectors.
// Author: Anushree chandak

// including header files
#include<iostream>
#include<vector>
using namespace std;
#include<ctime>
#include<cstdlib>
#include"TimeStamp.h" // including TimeStamp class

#include "SelectionSort.h" // Including selectionsort class


template<class T> T input(T,int); // prototype of template that adds random data to arrays/vectors
template<class T> void print(T,int); // prototype of template that prints arrays/vectors
int* copy(int[],int,int); // function that copies data from one array to another

// global arrays helping with the copying of arrays
int b1[20];
int b2[8000];

//main function
void main()
{
	const int size=20; // declaring size of small array/vector
	const int size1=8000; // declaring size for large array/vector
	int a_small[size]; // small array
	vector<int>v_small(size); // small vector
	int a_large[size1]; // large array
	vector<int>v_large(size1);// large vector

	int *a_small_copy; // pointer array to copy small array
	int *a_large_copy; // pointer array to copy large array
	vector<int>v_small_copy(size); // copying small vector
	vector<int>v_large_copy(size1); // copying large vector

	input(a_small,size); // filling small array with random data

	input(a_large,size1); // filling large array with random data

	a_small_copy=copy(a_small,size,1); // creating copy of small array

	a_large_copy=copy(a_large,size1,2); // creating copy of large array

	v_small=input(v_small,size); // filling small vector with random data

	v_large=input(v_large,size1); // filling large vector with random data

	v_small_copy=v_small; // creating copy of small vector
	v_large_copy=v_large; // creating copy of large vector

	

	SelectionSort s;
	cout<<"Printing ARRAY before sorting"<<endl;
	print(a_small,size); // print data before sorting 
	cout<<"Sorting with Recursive method"<<endl;
	print(s.RecursiveSort(a_small,size),size);// sort data  with recusrsion and print the data
	cout<<"Sorting With Iterative Method:"<<endl;
	print(s.IterativeSort(a_small_copy,size),size);// sort data with iterative method and print data 

	cout<<"Printing VECTOR before sorting"<<endl;
	print(v_small,size); // print data before sorting
	cout<<"Sorting with Recursive method"<<endl;
	print(s.RecursiveSort(v_small),size);// sort data with recursion and print the data
	cout<<"Sorting With Iterative Method:"<<endl;
	print(s.IterativeSort(v_small_copy),size);// sort data with iterative method and print data



	TimeStamp Time;
	cout<<"Time before sorting the large array with Recursive method:"<<endl; 
	cout<<"\n"<<Time.GetTime()<<endl;  // timestamp before sorting large array with recursion

	s.RecursiveSort(a_large,size1); // sort large array with recursion

	cout<<"Time after sorting the large array with Recursive method:"<<endl; 
	cout<<"\n"<<Time.GetTime()<<endl; // timestamp after sorting large array with recursion

	cout<<"Time before sorting the large array with Iterative method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl;  // timestamp before sorting large array with iteration


	s.IterativeSort(a_large_copy,size1); // sort large array with iteration

	cout<<"Time after sorting the large array with Iterative method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl; // timestamp after sorting large array with iteration

	cout<<"Time before sorting the large vector with Recursive method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl; // timestamp before sorting large vector with recursion

	s.RecursiveSort(v_large);  // sort large vector with recursion

	cout<<"Time after sorting the large vector with Recursive method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl;  // timestamp after sorting large vector with recursion

	cout<<"Time before sorting the large vector with Iterative method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl; // timestamp before sorting large vector with iteration

	s.IterativeSort(v_large_copy);// sort large vector with iteration

	cout<<"Time after sorting the large vector with Iterative method:"<<endl;
	cout<<"\n"<<Time.GetTime()<<endl; // timestamp before sorting large vector with iteration

}

// template defination to add data to arrays/vectors
template <class T>
T input(T a, int s)
{

	srand(s); // it produces the same input for vectors and arrays for fair comparision
	for (int i=0;i<s;i++)
	{
		a[i]=1+rand()%s; // creat random data and add it to arrays and vectors one by one
	}
	return a;	
}
// template defination to print array/vector
template <class T>
void print(T array2,int size)
{
	cout<<"data = [";
	for (int i=0;i<size;i++)
	{
		cout<< array2[i]<<" "; // print the elements of arrays/vectors one by one
	}
	cout<<"]"<<endl;
}
// function defination for copying arrays
int * copy(int b[],int size3,int option)
{
	if (option==1) // option 1 for small arrays
	{
		int s1=size3;
        

	for (int i=0;i<s1;i++)
	{
		b1[i]=b[i]; // copying array to a global variable for the ease of access
	}
	return b1;
	}
	else if(option==2)// option 2 for large arrays
	{
		
		
		int s2=size3;
	for (int i=0;i<s2;i++)
	{
		b2[i]=b[i]; // copying array to a global variable for the ease of access
	}
	return b2;
	}
}