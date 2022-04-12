#include<stdio.h>
#include<stdlib.h>

#define max_size 5

int q[max_size];
int front=-1;
int rear=-1;


void insertlq()
{
	int x;
	printf("Enter element to be inserted:\t");
	scanf("%d",&x);
	if(rear==max_size-1)
		printf("Queue is full\n");
	else if(rear==front && rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=x;

	}
	else
	{
		rear++;
		q[rear]=x;
	}
}

void deletelq()
{
	int x;
	if(front==-1 && rear==-1)
		printf("Queue is empty\n");
	else
	{
		x=q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front++;
		printf("Deleted element is:%d\n",x);

	}
}

void displaylq()
{
	int i;
	if(front==-1 && rear==-1)
		printf("Empty queue\n");
	else
	{
		printf("Elements are:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",q[i]);
	}
	printf("\n");
}
int main()
{
	while(1)
	{
		int c;
		printf("1.insert\n2.Delete\n3.Display\n4.Exit\n(NOTE:maximum size of queue is 5)\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			insertlq();
			break;
			case 2:
			deletelq();
			break;
			case 3:
			displaylq();
			break;
			case 4:
			exit(0);
			break;
		}
	}
	return 0;
}





