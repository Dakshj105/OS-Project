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
