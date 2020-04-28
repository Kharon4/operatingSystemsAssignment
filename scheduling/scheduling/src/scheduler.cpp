#include "scheduler.h"


long long int FCFSscheduler::getRunningID(std::vector<process>& readyList) {
	//assuming the process manager implementation can change
	long long rVal = -1;
	size_t smallestArrivalTime = 0;
	for (long long i = 0; i < readyList.size(); ++i) {
		if (readyList[i].arrivalTime < smallestArrivalTime || rVal < 0) {
			smallestArrivalTime = readyList[i].arrivalTime;
			rVal = i;
		}
	}
	return rVal;
}