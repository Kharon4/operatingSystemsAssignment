Data collected for analysis can be found in data\graph.xlsxs

This project must be compiled with MSVC on windows.

To compile :
Ensure windows sdk is updated to version 10.0.18362.0 , if not update windows sdk.
open the "scheduling.sln" file with visual studio 2019
Build/Run using the IDE
(since the project has multiple files every thing is configured insdie visual studio files)
The executable will be inside bin\Debug or bin\Release folder based on the confguration chosen.


Prebuilt executable :
Since it is a time comsuming process to configure a machine to compile the code, I'm including a prebuilt executable.
please find the executabe as follows bin/Release/x64/scheduling.exe
This is compiled for x64 windows platform. 

ProcessData :
Since the program expects the process data to be entered by user,
it must be entered in scheduling/processData.txt document with the following formatt:

processID(unsigned integer) ArrivalTime(unsigned integer) BurstTime(unsigned integer) priorityNo(unsigned integer)

Each process info must be entered in a new line.

NOTE : The processData.txt file must lie in the same dir as executable so if using pre built executables please modify:
       bin/Release/x64/processData.txt
