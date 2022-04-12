#include<stdio.h>
#include<stdlib.h>

void tower(int n,char s,char t,char d)
{
	if(n>0)
	{
		tower(n-1,s,d,t);
		printf("move disc %d from %c to %c\n",n,s,d);
		tower(n-1,t,s,d);		
	}

}

int main()
{
	int n,count;
	char s='s',t='t',d='d';
	scanf("%d",&n);
	tower(n,s,t,d);
	return 0;
}





