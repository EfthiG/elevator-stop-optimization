#include <stdio.h>

int cst(int a, int b, int *dest, int nrid) {
	int i,cost=0;
	for(i=0;i<nrid;i++) {
		if(a==0 && b <0) {
			cost += dest[i];
		}
		else if(b<0) {
			if(dest[i] > a) {
				cost += dest[i] - a;
			}
		}
		else if((dest[i] >= a) && (dest[i]<=b)) {
			if((dest[i]-a) <= (b - dest[i])) {
				cost += dest[i] -a;
			}
			else {
				cost += b - dest[i];
			}
		}
	}
	return cost;
}



int minc(int i, int j, int nfl, int *dest,int nrid) {
	int k, min, n;
	min = 5000;
	if(i!=0) {
		for(k=0;k<=j;k++) {
			n = minc(i-1, k, nfl, dest, nrid) - cst(k, -1, dest, nrid) + cst(k, j, dest, nrid) + cst(j, -1, dest, nrid);
			if(n < min) {
				min = n;
			}
		}
		return min;
	}
	else {
		return cst(0, -1, dest, nrid);
	}
}




int solve(int nrid, int nst, int *dest) {
	int i, nfl, min, minf,j,k;
	nfl=dest[0];
	min=5000;
	minf=0;
	for(i=0;i<nrid;i++) {
		if(dest[i]>nfl) {
			nfl = dest[i];
		}
	}
	for(j=0;j<=nfl;j++) {
		if(min>(k=minc(nst, j, nfl, dest, nrid))) {
			min = k;
			minf = j;
		}
	}
	if(nst!= 0) {
		printf("Last stop at floor %d\n", minf);
	}
	else {
		printf("No lift stops\n");
	}
	return min;
}




