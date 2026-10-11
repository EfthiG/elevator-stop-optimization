#include <stdio.h>
#include <stdlib.h>


int cst(int a,int b,int *dest,int nrid){ 
	int i,cost;
	cost=0;
	for(i=0 ; i<nrid ; i++){
		if(a==0 && b<0){          
			cost += dest[i];
		}
		else if(b<0){               
			if(dest[i]>a){
				cost += dest[i] - a;
			}
		}
		else if((dest[i]>=a) && (dest[i]<=b)){
			if((dest[i] - a) <= (b - dest[i])){
				cost += dest[i] - a;
			}
			else {
				cost += b - dest[i];
			}
		}
	}
	return cost;
}



int minc(int i,int j,int nfl,int *dest,int nrid,int **mem,int **fl){   
	int k,min,n,minf;                                 
	min=5000;
	if(i!=0)
	{ 
		for(k=0;k<=j;k++)
		{ 
			if(mem[i-1][k]>=0){
				n=mem[i-1][k];
			}else{
				n=minc(i-1,k,nfl,dest,nrid,mem,fl);
			}
			n=n-cst(k,-1,dest,nrid)+cst(k,j,dest,nrid)+cst(j,-1,dest,nrid);
			if((n<min) && (n>=0))    
			{ 
				min=n;
				minf=k;
			}
		}
		mem[i][j]=min;
		fl[i][j]=minf;
		return min;
	}
	else
	{ 
		int f = cst(0,-1,dest,nrid);
		mem[0][j]=f;
		fl[i][j]=0;
		return f;
	}
}


int solve(int nrid,int nst,int *dest){
	int i,nfl,min,minf,j,k,x,**fl;               
	nfl=dest[0];
	min=5000;
	minf=0;
	int **mem;
	for(i=0;i<nrid;i++)               
	{ 
		if(dest[i]>nfl){ 
			nfl=dest[i];
		}
	}
	mem=malloc((nst+1)*sizeof(int *));
	if(mem== NULL ){      
		return -1;
	}

	for(i=0;i<=nst;i++)
	{ 
		mem[i]=malloc((nfl+1)*sizeof(int));
		if(mem[i]== NULL ){
			return -1;
		}
	}
	fl=malloc((nst+1)*sizeof(int *));
	if(fl== NULL ){     
		return -1;
	}

	for(i=0;i<=nst;i++)
	{ 
		fl[i]=malloc((nfl+1)*sizeof(int));
		if(fl[i]== NULL ){
			return -1;
		}
	}

	for(j=0;j<=nfl;j++){
		for(i=0;i<=nst;i++){
			mem[i][j]= -1;
		}
		k=minc(nst,j,nfl,dest,nrid,mem,fl);
		if(min>k){
			min=k;
			minf=j;
		}
	} 

	for(i=0;i<=nst;i++) {
		for(j=0;j<=nfl;j++)
			printf("%d ",mem[i][j]);         
		printf("\n");
	}

	x=nst;
	if(nst!=0)
	{
		printf("Lift stops are:");
		while(fl[x][minf]!=0)
		{ 
			if(x==nst) {
				fl[0][x]=minf;
			}
			fl[0][x-1]=fl[x][minf];         
			minf=fl[x][minf];
			x--;
		}
		for(i=0;i<=nst;i++)
		{ 
			if(fl[0][i]!=0)
				printf("%d ",fl[0][i]);     
		}
		printf("\n");
	}
	else {                                        
		printf("No lift stops\n");
	}
		
	for(i=0;i<nst+1;i++) {                  
		free(mem[i]);
		free(fl[i]);
	}

	free(mem);
	free(fl);	

	return min;
}
