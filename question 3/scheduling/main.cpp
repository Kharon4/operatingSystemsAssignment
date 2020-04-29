#include <iostream>
#include "processManager.h"
#include "loader.h"

#include<conio.h>

void performTest(scheduler* schedulingScheme) {
	processManager PM(schedulingScheme);
	if (loadData("processData.txt", PM.processList))std::cout << "Failed to load the data \n";

	//start running
	process running;
	while (!PM.executionFinished()) {
		PM.update();

		std::cout << "current Time : " << PM.getTime() << "  , ";
		if (PM.getRunningProcess(running))std::cout << " no process running \n";
		else running.displayProcess();
	}

	//show stats
	double avgTurnAroundTime = 0;
	double avgWaitTime = 0;
	std::cout << "\nExecution completed\n\nStats:\n";
	for (long long int i = 0; i < PM.completedProcessList.size(); ++i) {
		std::cout << "Process id : " << PM.completedProcessList[i].P.processId <<
			"  , turnArroundTime :" << PM.completedProcessList[i].turnArroundTime <<
			"  , waitTime : " << PM.completedProcessList[i].waitTime << std::endl;
		avgTurnAroundTime += PM.completedProcessList[i].turnArroundTime;
		avgWaitTime += PM.completedProcessList[i].waitTime;
	}
	avgTurnAroundTime /= PM.completedProcessList.size();
	avgWaitTime /= PM.completedProcessList.size();
	std::cout << std::endl;
	std::cout << "Average turnaround time : " << avgTurnAroundTime << std::endl;
	std::cout << "Average wait time : " << avgWaitTime << std::endl;
}

int main() {

	std::cout << "press any key to start simulation \n\n";
	_getch();
	{
		std::cout << "#1 First Come First Serve \n\n";
		FCFSscheduler sc;
		performTest(&sc);
	}
	std::cout << "\n\nTesting finished press any key to move onto next test\n\n";
	_getch();
	{
		std::cout << "#2 Preemptive Shortest Job First \n\n";
		SJFPscheduler sc;
		performTest(&sc);
	}
	std::cout << "\n\nTesting finished press any key to move onto next test\n\n";
	_getch();
	{
		std::cout << "#3 NonPreemptive Shortest Job First \n\n";
		SJFNPscheduler sc;
		performTest(&sc);
	}
	std::cout << "\n\nTesting finished press any key to move onto next test\n\n";
	_getch();
	{
		std::cout << "#4 Nonpreemptive Priority  \n\n";
		priorityNPscheduler sc;
		performTest(&sc);
	}
	std::cout << "\n\nTesting finished press any key to move onto next test\n\n";
	_getch();
	{
		std::cout << "#5 Round Robin \n\n";
		roundRobinscheduler sc(2);
		performTest(&sc);
	}
	std::cout << "\n\nTesting finished press any key to close\n\n";
	_getch();
	return 0;
}