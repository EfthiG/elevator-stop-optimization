#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(){
	int nrid,f,nst,last,i,c;

	scanf("%d ",&nrid);              //read the number of persons
	if(nrid<0){         
		printf("Input error\n");
		return -1;
	}
 
	scanf("%d\n",&nst);              //read the maximum stops
	if(nst<0){ 
		printf("Input error\n");
		return -1;
	}

	int dests[nrid];
	for(i=0;i<nrid;i++)             //read every person's destination
	{
		scanf("%d",&dests[i]);
		if(dests[i]<0)
		{
			printf("Input error\n");
			return -1;
		}
	}
	c=solve(nrid,nst,dests);      
	printf("Cost is:%d\n",c);
}
