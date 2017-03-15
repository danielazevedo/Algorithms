#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

int nRows, nCols;

void printVector(int n, int m, int LCS[][m]){
	int i,j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			printf("%d ", LCS[i][j]);
		}
		printf("\n");
	}
}

int path(int i, int j, int P[][nCols], int T[][nCols]){
	if(i == 0 || i<j){
		T[i][j] = P[i][j];
		return T[i][j];
	}

	if(T[i][j] != -1){
		return T[i][j];
	}

	if(j==0){
		T[i][j] = path(i-1,j,P,T)+P[i][j];
		return T[i][j];
	}
	T[i][j] = max(path(i-1,j-1,P,T), path(i-1,j,P,T))+P[i][j];
	return T[i][j];

}

int main(){


	int nTest;
	scanf("%d\n",&nTest);



	int i, j, k, a, max=0;

	for (k = 0; k < nTest; ++k){
		scanf("%d",&nRows);
		nCols = nRows;
		int tabela[nRows][nCols];
		int T[nRows][nCols];
		for (i = 0; i < nRows; ++i){
			for (j = 0; j < nCols; ++j){
				tabela[i][j] = 0;
				T[i][j] = -1;
			}
		}
		for(i=0; i< nRows; i++){
			a = 0;
			for(j=0; j< i+1; j++){
				scanf("%d", &tabela[i][j]);
			}
		}
		for (i = 0; i < nCols; ++i){
			a = path(nRows-1,i,tabela,T);
			if(max<a)
				max = a;

		}
		printf("%d\n", max);
	}	
	return 0;

}
