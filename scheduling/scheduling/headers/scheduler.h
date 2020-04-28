#pragma once

#include "process.h"
#include <vector>


class scheduler {
public:
	virtual long long int getRunningID(std::vector<process> & readyList) { return -1; }
};


class FCFSscheduler : public scheduler {
public:
	long long int getRunningID(std::vector<process>& readyList);

};