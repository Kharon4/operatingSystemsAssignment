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

class SJFPscheduler : public scheduler {
public:
	long long int getRunningID(std::vector<process>& readyList);
};

class SJFNPscheduler : public scheduler {
private:
	size_t burstsLeft = 0;
	long long int chosen = -1;
public:
	long long int getRunningID(std::vector<process>& readyList);
};

class priorityNPscheduler : public scheduler {
private:
	size_t burstsLeft = 0;
	long long int chosen = -1;
public:
	long long int getRunningID(std::vector<process>& readyList);
};

class roundRobinscheduler : public scheduler {
private:
	size_t burstsLeft = 0;
	long long int chosen = -1;
	size_t quantum;
	bool dontMove = false;
public:
	roundRobinscheduler(size_t Quantum = 2) { quantum = Quantum; }
	long long int getRunningID(std::vector<process>& readyList);
};