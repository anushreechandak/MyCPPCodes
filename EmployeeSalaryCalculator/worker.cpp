//  FileName:    worker.cpp
// Description: Defines the member functions provided in the interface worker.h.
// Author:      Anushree Chandak
// Project:     worker(Programming in C++)
// Reference:   class notes and google.com
#include "worker.h"
#include<iostream>
#include<cmath>
using namespace std;


worker::worker() // constructor initialising the private variables
{
	manager_final=0;
	hourly_final=0;
	commission_final=0;
	piece_final=0;
	
}
double worker::manager() // function calculate the salary of manager type of employee
 {
	 double salary;
	 cout<<" Enter Weekly salary:";
	 cin>>salary;
	 cout<<" Commission worker's pay is $"<<salary<<endl;
	 manager_final=salary+manager_final;
	 return manager_final;
 }
double worker::hourly() // function calculate the salary of hourly worker type of employee
{
	double salary;
	double hours,total=0,extra;
	cout<<" Enter hourly salary:";
	cin>>salary;
	cout<<" Enter total hours worked:";
	cin>>hours;
	if (hours<=40) 
	{
		total=hours*salary;
	}
	else
	{
		extra=hours-40;
		total=(40*salary)+(1.5*extra*salary);// calculation of salary if hours worked are greater than 40.
	}
	cout<<" Worker's pay is: $"<<total<<endl;
	hourly_final=total+hourly_final;
	return hourly_final;

}
double worker::commission() // function calculate the salary of commission worker type of employee
{
	double sales,total=0;
	cout<<" Enter gross weekly sales:";
	cin>>sales;
	total=250+(5.7*sales/100);
	cout<<" Commission worker's pay is: $"<<total<<endl;
	commission_final=commission_final+total;
	return commission_final;
}
double worker::piece() //// function calculate the salary of pieceworker type of employee
{
	double total=0,wage;
	int p;
	cout<<" Enter number of pieces:";
	cin>>p;
	cout<<" Enter wage per piece:";
	cin>>wage;
	total=p*wage;
	cout<<" Piece worker's pay is: $"<<total<<endl;
	piece_final=piece_final+total;
	return piece_final;
}



 void worker::calculate() // function that selects the appropriate method to calculate the salary of selected employee
{
	int paycode;
	cout<<" Enter the paycode(-1 to end):";
	cin>>paycode;
	while (paycode!=-1) // loop should end when paycode is provided as -1
	{
		switch (paycode)
		{
		case 1: // manager type of employee is selected
			cout<<"\n Manager selected:"<<endl;
			manager();
			cout<<" \n Enter the paycode(-1 to end):";
			cin>>paycode;
			break;
		case 2: // hourly worker type of employee is selected
			cout<<"\n Hourly Worker selected:"<<endl;
			hourly();
			cout<<"\n Enter the paycode(-1 to end):";
			cin>>paycode;
			break;
		case 3: // commission worker type of employee is selected
			cout<<"\n Commision Worker selected:"<<endl;
			commission();
			cout<<"\n Enter the paycode(-1 to end):";
			cin>>paycode;
			break;
		case 4://// pieceworker type of employee is selected
			cout<<" \n PieceWorker selected:"<<endl;
			piece();
			cout<<"\n Enter the paycode(-1 to end):";
			cin>>paycode;
			break;
		default:
			cout<<"Invalid Entry!!"<<endl;
			cout<<"\n Enter the paycode(-1 to end):";
			cin>>paycode;
            break;
		}// end switch
	}// end while
barchart();  // call function barchart
}
void worker::barchart() // function creats barchart for the total spendings on perticular type of employee.
 {
	 manager_final=round(manager_final/100); // using round function to get a integer value.
	 	 cout<<"Managers: ";
		 while(manager_final) // printing the no of '*' equal to the integer value calculated above.
	 {
		 cout<<"*"; 
		 manager_final--;
	 }
 cout<<endl;

 hourly_final=round(hourly_final/100);// using round function to get a integer value.
	 	 cout<<"Hourly Workers: ";
	 while(hourly_final) // printing the no of '*' equal to the integer value calculated above.
	 {
		 cout<<"*";
		 hourly_final--;
	 }
 cout<<endl;
 
 commission_final=round(commission_final/100); // using round function to get a integer value.
 
	 	 cout<<"Commission Workers: ";
	 while(commission_final) // printing the no of '*' equal to the integer value calculated above.
	 {
		 cout<<"*";
		 commission_final--;
	 }
 cout<<endl;

 piece_final=round(piece_final/100); // using round function to get a integer value.
	 	 cout<<"PieceWorkers: ";
	 while(piece_final) // printing the no of '*' equal to the integer value calculated above.
	 {
		 cout<<"*";
		 piece_final--;
	 }
 cout<<endl;
 }

double worker::round(double x)
{
    double y,z;
	y=x+0.5;
	z=int(x)+1;

	if (y>=z) // if decimal part is greater than 0.5 then rounding to next integer
	 {
		 x=ceil(x);
	 }
	 else    // otherwise rounding to lower integer.
	 {
		 x=floor(x);
	 }
	return x;
}
 

