#include<stdio.h>
#include<stdlib.h>

#define max_size 5
int q[max_size];
int front=-1,rear=-1;

void insertcq()
{
	int x;
	printf("Enter element to be inserted:\t");
	scanf("%d",&x);
	if(front==(rear+1)%max_size) // joint condition for both linear and circular queues which are filled
		printf("queue is full\n");
	else
	{
		if(front==-1 && rear=-1)
		{
			front=0;
			rear=0;
			q[rear]=x;
		}
		else
		{
			rear=(rear+1)%max_size;
			q[rear]=x;
		}
	}
}

void deletecq()
{
	if(front==-1 && rear==-1)
		printf("Queue is empty\n");
	else
	{
		printf("Deleted element is:%d\n",q[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;

		}
		else
			front=(front+1)%max_size;
	}
}

void displaycq()
{
	int i;
	if(front==-1 && rear==-1)
		printf("Queue is empty\n");
	else
	{
		printf("The elements are:\n");
		for(int i=front;i!=rear;i=(i+1)%max)
			printf("%d\t",&q[i]);
		printf("%d\n",q[i]);
		// if(front<=rear) //normal
		// {
		// 		for(i=front;i<=rear;i++)  
		// 		printf("%d\t",q[i]);
		// }
		// else
		// {
		// 	for(i=front;i<max_size;i++)
		// 		printf("%d\t",q[i]);
		// 	for(i=0;i<=rear;i++)
		// 		printf("%d\t",q[i]);
		// }
		printf("\n");
	}
}

int main()
{
	while(1)
	{
		int c;
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n(NOTE:maximum size of queue is 5)\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			insertcq();
			break;
			case 2:
			deletecq();
			break;
			case 3:
			displaycq();
			break;
			case 4:
			exit(0);
			break;
		}
	}
	return 0;
}





