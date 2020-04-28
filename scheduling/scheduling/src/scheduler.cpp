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

long long int SJFPscheduler::getRunningID(std::vector<process>& readyList) {
	//assuming the process manager implementation can change
	long long rVal = -1;
	size_t smallestBurstTime = 0;
	for (long long i = 0; i < readyList.size(); ++i) {
		if (readyList[i].burstTime < smallestBurstTime || rVal < 0) {
			smallestBurstTime = readyList[i].burstTime;
			rVal = i;
		}
	}
	return rVal;
}

long long int SJFNPscheduler::getRunningID(std::vector<process>& readyList) {
	if(burstsLeft!=0)burstsLeft--;
	if (burstsLeft > 0) {
		return chosen;
	}
	//assuming the process manager implementation can change
	long long rVal = -1;
	size_t smallestBurstTime = 0;
	for (long long i = 0; i < readyList.size(); ++i) {
		if (readyList[i].burstTime < smallestBurstTime || rVal < 0) {
			smallestBurstTime = readyList[i].burstTime;
			rVal = i;
		}
	}
	burstsLeft = smallestBurstTime;
	chosen = rVal;
	return rVal;
}