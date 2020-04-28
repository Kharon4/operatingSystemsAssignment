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


long long int priorityNPscheduler::getRunningID(std::vector<process>& readyList) {
	if (burstsLeft != 0)burstsLeft--;
	if (burstsLeft > 0) {
		return chosen;
	}
	//assuming the process manager implementation can change
	long long rVal = -1;
	size_t largestPriority = 0;
	for (long long i = 0; i < readyList.size(); ++i) {
		if (readyList[i].priorityNo > largestPriority || rVal < 0) {
			largestPriority = readyList[i].priorityNo;
			rVal = i;
		}
	}
	if(rVal!=-1)
		burstsLeft =readyList[rVal].burstTime;
	chosen = rVal;
	return rVal;
}

long long int roundRobinscheduler::getRunningID(std::vector<process>& readyList) {
	if (burstsLeft != 0)burstsLeft--;
	if (burstsLeft > 0) {
		return chosen;
	}
	//assuming the process manager implementation can change
	long long rVal = -1;
	if (readyList.size() > 0) {
		rVal = chosen;
		if (!dontMove)rVal += 1;
		if (rVal >= readyList.size())rVal -= readyList.size();
	}


	if (rVal != -1) {
		if (readyList[rVal].burstTime > quantum) {
			burstsLeft = quantum;
			dontMove = false;
		}
		else {
			burstsLeft = readyList[rVal].burstTime;
			dontMove = true;
		}
	}
	chosen = rVal;
	return rVal;
}