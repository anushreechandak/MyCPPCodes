//Filename: SelectionSort.cpp
// Description: This file contains definations of various function 
//              used to sort arrays and vectors using selectionsort algorithm
// Author: Anushree chandak

// including header files
#include<iostream>
#include<vector>
using namespace std;
#include<ctime>
#include<cstdlib>
#include "SelectionSort.h"

// empty constructor
SelectionSort::SelectionSort()
{
}
// sorting array with iterative method
int* SelectionSort::IterativeSort(int array[],int arraysize)
{
	int choice; // ask user for ascending or descending option
	cout<<"\n Enter choice 1 for ascending and 2 for descending order"<<endl;
	cin>>choice;
	if (choice==1) // if choice is 1 sort array ascendingly
	{
		ascending_array(array,arraysize); 
	}
	else  // else sort array descendingly
	{ 
		descending_array(array,arraysize);
	}
	return array;
}
// sorting vector with iterative method
vector<int> SelectionSort::IterativeSort(vector<int> &vctr)
{
	
	int choice;
	size_t sizeofvector=vctr.size();
	cout<<"\n Enter choice 1 for ascending and 2 for descending order"<<endl;
	cin>>choice;
	
	if (choice==1) // if choice is 1 sort vector ascendingly
	{
		ascending_vector(vctr);
	}
	else 
	{ 
		descending_vector(vctr); // if choice is 1 sort vector descendingly
	}
	return vctr;
}
// sorting array with recursive method
int* SelectionSort::RecursiveSort(int array2[],int s)
{
	int choice;
	cout<<"\n Enter choice 1 for ascending and 2 for descending order"<<endl;
	cin>>choice;
	int first=0;
	int last=s; // size of array
	if (choice==1)  // choice 1 for ascending 
	{
		R_ascending_array(array2,last);
		
	}
	else // else descending
	{ 
		R_descending_array(array2,last);
		
	}
	return array2;

}
// sorting vector with recursive method
vector<int> SelectionSort::RecursiveSort(vector<int> &vctr1)
{
	int choice;
	size_t last=vctr1.size();
	cout<<"\n Enter choice 1 for ascending and 2 for descending order"<<endl;
	cin>>choice;
	if (choice==1) // choice 1 for ascending
	{
		R_ascending_vector(vctr1,last);
	}
	else // else descending
	{ 
		R_descending_vector(vctr1,last);
	}
    return vctr1;
}
// sorting vector ascendingly with iterative method
void SelectionSort::ascending_vector(vector<int>& v1)
{
		int temp=0; // get temparory variable for swapping
		size_t size=v1.size();  // get the size of the vector
	for (int i = 0; i < size; i++)
		{
		     for (int j = i+1; j < size; j++)
			 {
			      if (v1[i] > v1[j]) // if first value is greater than its next value
			           {
						   //swap the values
				            temp = v1[i];
				            v1[i] = v1[j];
				            v1[j] = temp;
				  	    }
			 }
		}
}

// sorting vector descendingly with iterative method
void SelectionSort::descending_vector(vector<int>&v1)
{
		int temp1=0; // get temparory variable for swapping
		size_t size1=v1.size(); // get the size of the vector
	for (int i = 0; i < size1; i++)
		{
		     for (int j = i+1; j < size1; j++)
			 {
			      if (v1[i] < v1[j]) // if first value is less than its next value
			           {
						   //swap the values
				            temp1 = v1[i];
				            v1[i] = v1[j];
				            v1[j] = temp1;
				  	    }
			 }
		}
	
}
// sorting array ascendingly with iterative method
void SelectionSort::ascending_array(int array1[],int size)
{
	int temp=0; // get temparory variable for swapping
	for (int i = 0; i < size; i++)
		{
		     for (int j = i+1; j < size; j++)
			 {
			      if (array1[i] > array1[j]) // if first value is greater than its next value then swap the values
			           {
				            temp = array1[i];
				            array1[i] = array1[j];
				            array1[j] = temp;
				  	    }
			 }
		}
}
// sorting array descendingly with iterative method
void SelectionSort::descending_array(int array2[],int size1)
{
		int temp1=0; // get temparory variable for swapping
	for (int i = 0; i < size1; i++)
		{
		     for (int j = i+1; j < size1; j++)
			 {
			      if (array2[i] < array2[j])// if first value is less than its next value then swap the values
			           {
				            temp1 = array2[i];
				            array2[i] = array2[j];
				            array2[j] = temp1;
				  	    }
			 }
		}
	

}
// sorting array ascendingly with recursive method
void SelectionSort::R_ascending_array(int arr[],int last)
{
	int temp=0;  // get temparory variable for swapping
		int first=0; // get the counter
		int i=0;
	
		for(i=first;i<last;i++)
		{
            if(arr[i]>arr[first]) //if first value is less than next value 
			{
				first=i; // update the counter to that next value
			}
		}
		//swap the values
		temp=arr[last-1];
		arr[last-1]=arr[first];
		arr[first]=temp;
		if(last>1)	// if there are more elements to be sorted then call this function sgain with a decremented counter
		{
		R_ascending_array(arr,--last);
		}
}
// sorting array descendingly with recursive method
void SelectionSort::R_descending_array(int arr[],int last)
{
	int temp1=0;// get temparory variable for swapping
		int first=0;// get the counter
		int i;
	
		for(i=first;i<last;i++)
		{
            if(arr[i]<arr[first]) //if first value is greater than next value update the counter to that next value
			{
				first=i; 
			}
		}
		//swap the values
		temp1=arr[last-1];
		arr[last-1]=arr[first];
		arr[first]=temp1;
		if(last>1) // if there are more elements to be sorted then call this function sgain with a decremented counter
		{
		R_descending_array(arr,--last);
		}
}
// sorting vector ascendingly with recursive method
void SelectionSort::R_ascending_vector(vector<int>& v1,int last)
{
	int temp=0; // get temparory variable for swapping
		int first=0; // get the counter
		int i=0;
	    
		for(i=first;i<last;i++)
		{
            if(v1[i]>v1[first]) //if first value is less than next value update the counter to that next value
			{
				first=i;
			}
		}
		//swap the values
		temp=v1[last-1];
		v1[last-1]=v1[first];
		v1[first]=temp;
		if(last>1)	// if there are more elements to be sorted then call this function sgain with a decremented counter
		{
		R_ascending_vector(v1,--last);
		}
}
// sorting vector descendingly with recursive method
void SelectionSort::R_descending_vector(vector<int>& v1,int last)
{
	int temp=0;// get temparory variable for swapping
		int first=0; // get the counter
		int i=0;
	    
		for(i=first;i<last;i++)
		{
            if(v1[i]<v1[first])//if first value is greater than next value update the counter to that next value
			{
				first=i;
			}
		}
		//swap the values
		temp=v1[last-1];
		v1[last-1]=v1[first];
		v1[first]=temp;
		if(last>1)	// if there are more elements to be sorted then call this function sgain with a decremented counter
		{
		R_descending_vector(v1,--last);
		}
}