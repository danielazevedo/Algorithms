#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

void printVector(int n, int m, int LCS[][m]){
	int i,j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			printf("%d ", LCS[i][j]);
		}
		printf("\n");
	}
}

int lcs(int *a, int *b, int n, int m, int LCS[][m]){
	int i,j;
	
	for (i = 0; i < n; ++i){
		LCS[i][0] = 0;
	}
	for (j = 0; j < m; ++j){
		LCS[0][j] = 0;
	}

	for (i = 1; i < n; ++i){
		for (j = 1; j < m; ++j){
			if(a[i-1] == b[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else{
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			} 

		}
	}
	return LCS[n-1][m-1];
}


int main(){

	int N1, N2, i, j, c=1;
	while(1){
		scanf("%d %d",&N1, &N2);
		if(N1 == 0 && N2 == 0)
			break;

		int t1[N1];
		int t2[N2];
		for (i = 0; i < N1; ++i){
			scanf("%d",&t1[i]);
		}

		for (j = 0; j < N2; ++j){
			scanf("%d",&t2[j]);
		}
		int LCS[N1+1][N2+1];

		int res = lcs(t1,t2, N1+1, N2+1, LCS);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", c, res);
		c++;

	}
	return 0;
}