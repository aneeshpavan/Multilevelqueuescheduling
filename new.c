#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<pthread.h>
int main()
{
int priority[20],bursttime[20], process[20], waitingtime[20],turnaroundtime[20],i, k, numberofprocesses, temp;
float avgwaitingtime, avgturnaround;
printf("Enter the number of processes :");
scanf("%d",&numberofprocesses);
for(i=0;i<numberofprocesses;i++)
{
priority[i] = i;
printf("\nEnter the Burst Time of Process %d :",i);
scanf("%d",&bursttime[i]);
printf("Enter the System/User Process : ");
scanf("%d", &process[i]);
}
for(i=0;i<numberofprocesses;i++)
for(k=i+1;k<numberofprocesses;k++)
if(process[i] > process[k])
{
temp=priority[i];
priority[i]=priority[k];
priority[k]=temp;
temp=bursttime[i];
bursttime[i]=bursttime[k];
bursttime[k]=temp;
temp=process[i];
process[i]=process[k];
process[k]=temp;
}
avgwaitingtime = waitingtime[0] = 0;
avgturnaround = turnaroundtime[0] = bursttime[0];
for(i=1;i<numberofprocesses;i++)
{
waitingtime[i] = waitingtime[i-1] + bursttime[i-1];
turnaroundtime[i] = turnaroundtime[i-1] + bursttime[i];
avgwaitingtime = avgwaitingtime + waitingtime[i];
avgturnaround = avgturnaround + turnaroundtime[i];
}
printf("\n   PROCESS\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<numberofprocesses;i++)
printf("\n\t%d \t\t %d \t\t %d \t\t %d \t\t %d \n",priority[i],process[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
printf("\nAverage Waiting Time is : %f\n",avgwaitingtime/numberofprocesses);
printf("\nAverage Turnaround Time is : %f\n",avgturnaround/numberofprocesses);
return 0;
}
