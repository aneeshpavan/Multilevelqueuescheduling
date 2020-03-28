Multilevel queue scheduling algorithm is used in situations in which the processes can be divided into groups in a multi-queue scheduling algorithm, the number of queues would be 'n' where 'n' is the number of categories the processes are listed into. Every queue will be given priority and will have its own programming algorithm such as round-robin scheduling or FCFS.  For the process in a queue to execute, all the queues of priority higher than it should be empty, meaning the process in those high priority queues should have completed its execution. In this scheduling algorithm, once assigned to a queue, the process will not move to any other queues.

Total Number of Processes, Burst Time, System/User Process for these inputs will be taken by the USER.
Burst time: Burst time is the total time taken by the process for its execution on the CPU.
Waiting time: Waiting time is the total time spent by the process in the ready state waiting for CPU
For Calculating Waiting Time:  
		Waiting Time = Turnaround time – Burst Time
					(OR)
		waitingtime[i] = waitingtime[i-1] + bursttime[i-1]; I used this in my CODE.
Turnaround Time: Turnaround time is the total amount of time spent by the process from coming in the ready state for the first time to its completion.
For Calculating Turnaround Time: 
		Turnaround Time = Burst Time + Waiting Time 
					(OR)
		Turnaround Time = Exit Time – Arrival Time
					(OR)
		turnaroundtime[i] = turnaroundtime[i-1] + bursttime[i]; I used this in my CODE.
For Calculating Average Waiting Time:
		Total Waiting Time / Number of Processes
					(OR)
		Average Waitingtime = Average Waiting Time + Waiting Time[i];
		Average Waitingtime/Number of Processes; I used this in my CODE.
For Calculating Average Turnaround Time:
		Total Turnaround Time / Number of Processes
					(OR)
		Average Turnaround = average Turnaround + Turnaround Time[i];
		Average Turnaround / Number of Processes; I used this in my CODE.


For Executing the CODE in Operating System (Ubuntu):
	Open Terminal in the file location
 	Gcc Filename.c // GCC is for compiling the CODE
	After compiling,
	./a.out //for Getting the output
	Enter the number of processes: // Input will be given by the USER
	Enter the Burst Time of Process _: //Input will be given by the USER
	Enter the System/User Process:  //Input will be given by the USER
	Will be Repeated till the number of processes completes
	Then the Output will be in tabular format of Process, System/user Process, burst time, Waiting Time, Turnaround Time and output for Average waiting time and Turnaround time will be Printed.

