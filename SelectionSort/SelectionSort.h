//Filename: SelectionSort.h
// Description: This file contains declarions of various function 
//              used to sort arrays and vectors using selectionsort algorithm
// Author: Anushree chandak

// including header files
#pragma once
#include<iostream>
#include<vector>
class SelectionSort
{
public:
	SelectionSort(); // constructor
	int* RecursiveSort(int[],int); // recursive sort for arrays
	vector<int> RecursiveSort(vector<int> &); // recursive sort for vectors
	int* IterativeSort(int[],int);	//iterative sort for arrays
	vector<int> IterativeSort(vector<int> &);//iterative sort for vectors
	void ascending_vector(vector<int>&); // sorting vector ascendingly for iterative method
	void descending_vector(vector<int>&);// sorting vector descendingly for iterative method
	void ascending_array(int[],int);// sorting array ascendingly for iterative method
	void descending_array(int[],int);// sorting array descendingly for iterative method
	void R_ascending_array(int[],int);// sorting array ascendingly for recursive method
	void R_descending_array(int[],int);// sorting array descendingly for recursive method
	void R_ascending_vector(vector<int>&,int);// sorting vector ascendingly for recursive method
	void R_descending_vector(vector<int>&,int);// sorting vector descendingly for recursive method

};

