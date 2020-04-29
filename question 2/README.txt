This project must be compiled with MSVC on windows.

The source code for this question has been divided into 2 parts
-Project 1
	Contains code for taking input, creating shared memory
	Compiles to Program1.exe
	Source code inside InterProcessCommunication folder
-Project 2
	Contains code for displaying output
	Compiles to Program2.exe
	Source code inside Program2 folder	

To compile :
Ensure windows sdk is updated to version 10.0.18362.0 , if not update windows sdk.
open the "InterProcessCommunication.sln" file with visual studio 2019
Build/Run using the IDE(build one project at a time)
(since the project has multiple files every thing is configured insdie visual studio files)
The executable will be inside bin\Debug or bin\Release folder based on the confguration chosen.

Execution order :
Any program ie. Program1.exe or Program2.exe can be started first.
The code implemets a robust method that is independent of the execution order.

Prebuilt executable :
Since it is a time comsuming process to configure a machine to compile the code, I'm including a prebuilt executable.
please find the executabe as follows bin/Release/x64/Program1.exe and bin/Release/x64/Program2.exe
These are compiled for x64 windows platform.


 
