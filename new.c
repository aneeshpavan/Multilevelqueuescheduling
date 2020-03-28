#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<pthread.h>
int arrival1[30],arrival2[30],priority2[30],process2[30],arrival3[30];
int burst1[30],burst2[30],burst3[30];
int Total=0,t1=0,t2=0,t3=0;
int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;
int total,x,temp[30],counter=0;
float averagewaiting1=0.0,averageturnaround1=0.0;
int p,waiting3[30],turnaround3[30];
float averagewaiting3=0.0,averageturnaround3=0.0;
int position,q,temp1,sum=0,waiting2[30],turnaround2[30];
float averagewaiting2,averageturnaround2;

void roundrobin()
{
	printf("Time Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		temp[i]=burst1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=4&&temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for %d units",i+1,temp[i]); 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1; 
        } 
        else if(temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for 4 units",i+1); 
            temp[i]=temp[i]-4; 
            total=total+4; 
        } 
        if(temp[i]==0&&counter==1) 
        { 
            x--; 
            printf("\nProcess[%d]\t\t%d\t\t%d\t\t\t%d",i+1,burst1[i],total-arrival1[i],total-arrival1[i]-burst1[i]);
            averagewaiting1=averagewaiting1+total-arrival1[i]-burst1[i]; 
            averageturnaround1=averageturnaround1+total-arrival1[i]; 
            counter = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(arrival1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    averagewaiting1=averagewaiting1/j;
    averageturnaround1=averageturnaround1/j;
    printf("\nAverage Waiting Time:%f",averagewaiting1); 
    printf("\nAverage Turnaround Time:%f\n",averageturnaround1); 
}

void priority()
{
	for(i=0;i<k;i++)
    {
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(priority2[q]<priority2[position])
            {
                position=q;
            }
        }
        temp1=priority2[i];
        priority2[i]=priority2[position];
        priority2[position]=temp1; 
        
        temp1=burst2[i];
        burst2[i]=burst2[position];
        burst2[position]=temp1;
        
        temp1=process2[i];
        process2[i]=process2[position];
        process2[position]=temp1;
    }
    waiting2[0]=0;
    for(i=1;i<k;i++)
    {
        waiting2[i]=0;
        for(q=0;q<i;q++)
        {
            waiting2[i]=waiting2[i]+burst2[j];
        }
        sum=sum+waiting2[i];
    }
    averagewaiting2=sum/k;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turnaround2[i]=burst2[i]+waiting2[i];
        sum=sum+turnaround2[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t\t%d\n",process2[i],burst2[i],waiting2[i],turnaround2[i]);
    }
    averageturnaround2=sum/k;
    printf("\nAverage Waiting Time:\t%f",averagewaiting2);
    printf("\nAverage Turnaround Time:\t%f\n",averageturnaround2);
    
    for(i=0;i<k;i++)
    {
    	while(burst2[i]!=0)
    	{
    		if(burst2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units",i+1);
				burst2[i]=burst2[i]-10;
			}
			else if(burst2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burst2[i]);
				burst2[i]=0;
			}
		}
	}

}

void firstcomefirstserve()
{
	waiting3[0] = 0;   
    for(i=1;i<l;i++)
    {
        waiting3[i] = 0;
        for(p=0;p<l;p++)
        {
            waiting3[i]=waiting3[i]+burst3[p];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<l;i++)
    {
        turnaround3[i]=burst3[i]+waiting3[i];
        averagewaiting3=averagewaiting3+waiting3[i];
        averageturnaround3=averageturnaround3+turnaround3[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t\t%d\n",i+1,burst3[i],waiting3[i],turnaround3[i]);
    }
    averagewaiting3=averagewaiting3/l;
    averageturnaround3=averageturnaround3/l;
    printf("\nAverage Waiting Time=%f",averagewaiting3);
    printf("\nAverage Turnaround Time=%f",averageturnaround3);
    for(i=0;i<l;i++)
    {
    	while(burst3[i]!=0)
    	{
    		if(burst3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units",i+1);
				burst3[i]=burst3[i]-10;
			}
			else if(burst3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burst3[i]);
				burst3[i]=0;
			}
		}
	}
}

void roundrobin1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

int main()
{
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
			arrival1[j]=at[i];
			burst1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival2[k]=at[i];
			burst2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
			arrival3[l]=at[i];
			burst3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	
	roundrobin1();
	roundrobin();
	firstcomefirstserve();
	priority();
	
	return 0;
}
