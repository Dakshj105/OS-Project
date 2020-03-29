/* Two types of people can enter into a library- students and teachers. After entering the library, the visitor
searches for the required books and gets them. In order to get them issued, he goes to the single cpu which is 
there to process the issuing of books. Two types of queues are there at the counter-one for students and one for 
teachers. A student goes and stands at the tail of the queue for students and similarly the teacher goes and stands 
at the tail of the queue for teachers (fifo). If a student is being serviced and a teacher arrives at the counter, he 
would be the next person to get service (priority-non preemptive). If two teachers arrive at the same time, they will
stand in their queue to get service (fifo). Wap to ensure that the system works in a non-chaotic manner. 

• If a teacher is being served and during the period when he is being served, another teacher comes, then that 
teacher would get the service next. This process might continue leading to increase in waiting time of students. 
Ensure in your program that the waiting time of students is minimized.*/

#include<stdio.h>
int main()
{
	int p[50],bt[50], su[50], wt[50],tat[50],i, k, n, temp;
	float wtavg, tatavg;
	printf("Enter the number of PROCESS  in the queue --- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time for process  %d --- ", i);
		scanf("%d",&bt[i]);
		printf("teacher/student process (0/1) ? --- ");
		scanf("%d", &su[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(su[i] > su[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nPROCESS\t\t TEACHER/STUDENT PROCESS  \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
	}

	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);

	return 0;
}

