#pragma once
#include <iostream>


class process {
public:
	size_t processId;
	size_t arrivalTime;
	size_t burstTime;
	size_t priorityNo;
	void displayProcess() { 
		std::cout << 
		"process : " << processId <<
		"  , arrived at : " << arrivalTime <<
		"  , remaining burst time :" << burstTime <<
		"  , PR no :" << priorityNo
		<< std::endl; 
	}
};