#pragma once
#include "process.h"
#include "scheduler.h"
#include <vector>

class processManager {
private:
	std::vector<process> readylist;
	long long currentExecutingId;
	size_t currentTime;
	scheduler* sc;
public:
	processManager(scheduler * SC);
	std::vector<process> processList;
	void update();
	bool getRunningProcess(process & OUTprocess);
	size_t getTime();//only valid after first update
	bool executionFinished();
};
