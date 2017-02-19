// FileName:    worker.h
// Description: Defination of class worker that calculates different types of salaries according to the employee.
// Author:      Anushree Chandak
// Project:     worker

#pragma once

class worker
{
public:
	worker();
	void calculate(); // function that selects the different employee based on the paycode provided.
	
private:
	// next 4 functions are used to calculate the actual salaries
	// of diffrent type of employee taking the appropriate input from the user.
	double manager(); 
	double hourly();
	double commission();
	double piece();
	void barchart();// creats the barchart
	double round(double);// function used to rounding off the number.
	// next 4 variables are used to save the total spendings on the perticular type of employee.
	double manager_final;
	double commission_final;
	double hourly_final;
	double piece_final;
};

