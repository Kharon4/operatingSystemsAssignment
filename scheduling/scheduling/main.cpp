#include <iostream>
#include "processManager.h"
#include "loader.h"

int main() {
	FCFSscheduler sc;
	processManager PM(&sc);
	if (loadData("processData.txt", PM.processList))std::cout << "Failed to load the data \n";

	//start running
	process running;
	while (!PM.executionFinished()) {
		PM.update();

		std::cout << "current Time : " << PM.getTime() << "  , ";
		if (PM.getRunningProcess(running))std::cout << " no process running \n";
		else running.displayProcess();
	}

	return 0;
}