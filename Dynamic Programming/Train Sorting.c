#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lis(int n, unsigned int s[n], int LIS[n]){
	int i,j, max=0;
	LIS[0] = 1;
	for (i = 1; i < n; ++i){
		LIS[i] = 0;
		for (j = 0; j < i; ++j){
			if (s[j] < s[i] && LIS[j] > LIS[i])
				LIS[i] = LIS[j];
		}
		LIS[i] = LIS[i] + 1;
		
	}
	max=0;
	for (i = 0; i < n; ++i){
		if(LIS[i]>max)
			max = LIS[i];
	}
	return max;
}




int main(){
	
	int n, i;
	scanf("%d",&n);
	unsigned int vetor[n];
	for (i = 0; i < n; ++i){
		scanf("%d",&vetor[i]);
	}
	int LIS[n];
	int max = lis(n,vetor,LIS);
	printf("%d\n",max);
	return 0;
}