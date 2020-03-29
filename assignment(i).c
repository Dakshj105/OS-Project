#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t L1=PTHREAD_MUTEX_INITIALIZER;
int rs1,rs2;
int assignment1=0, assignment2=0, assignment3=0;
void* teacher1()
{
	pthread_mutex_lock(&L1);
	printf("\n1st resource which is shared:-\n");
	scanf("%d",&rs1);
	printf("\n2nd resource which is shared:-\n");
	scanf("%d",&rs2);
	pthread_mutex_unlock(&L1);
}
void* student1()
{
	pthread_mutex_lock(&L1);
	assignment1=1;
	printf("\nStudent 1's assignment is finished\n");
	pthread_mutex_unlock(&L1);
}
void* student2()
{
	pthread_mutex_lock(&L1);
	assignment2=1;
	printf("\nStudent 2's assignment is finished\n");
	pthread_mutex_unlock(&L1);
}
void* student3()
{
	pthread_mutex_lock(&L1);
	assignment3=1;
	printf("\nStudent 3's assignment is finished\n");
	pthread_mutex_unlock(&L1);
}

int main()
{

	pthread_t teacher,student;
	printf("Resources are:-\n1) Press \n2) Pen \n3)Question_paper");

	while(1)
	{
		if(assignment1==1 && assignment2==1 && assignment3==1)
		{
			printf("Teacher and Student are now synchronized\n");
			break;
		}
		pthread_create(&teacher,NULL,teacher1,NULL);
		pthread_join(teacher,NULL);
		if((rs1==2 && rs2==3 || rs1==3 && rs2==2) && assignment1==0)
		{
			pthread_create(&student,NULL,student1,NULL);
			pthread_join(student,NULL);
		}
		else if((rs1==1 && rs2==3 || rs1==3 && rs2==1) && assignment2==0)
		{
			pthread_create(&student,NULL,student2,NULL);
			pthread_join(student,NULL);
		}
		else if((rs1==1 && rs2==3 || rs1==3 && rs2==1) && assignment3==0)
		{
			pthread_create(&student,NULL,student3,NULL);
			pthread_join(student,NULL);
		}
		else if((rs1!=1 && rs1!=2 && rs1!=3) || (rs2!=1 && rs!=2 && rs!=3) || rs1==rs2)
		{
			printf("Invalid Choice")
		}
		else
		{
			printf("Student's assignment already completed")
		}
	}

}
