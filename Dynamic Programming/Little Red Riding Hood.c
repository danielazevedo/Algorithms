#include <stdio.h>
#include <stdlib.h>

int nW;
unsigned long count(int n, int m, unsigned long T[][m], int tabela[][2]){
	
	int i, j, k;
	for (i = 0; i < n; ++i){
		T[i][0] = 1;
	}
	for (j = 0; j < m; ++j){
		T[0][j] = 1;
	}

	for (k = 0; k < nW; ++k){
		T[tabela[k][0]][tabela[k][1]] = 0;
	}

	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
		
			if(T[i][j] != 0){
				if(j==0 && i==0)
					T[i][j] = 1;
				else if(i==0){
					T[i][j] = T[i][j-1];
				}
				else if(j==0){
					T[i][j] = T[i-1][j];
				}
				else{
					T[i][j] = T[i-1][j] + T[i][j-1];
				}
			}
		}
	}
	return T[n-1][m-1];
	
}

void printVector(int n, int m, unsigned long t[][m]){
	int i,j;
	for (i = n-1; i >= 0; i--){
		for (j = 0; j < m; ++j){
			printf("|%ld", t[i][j]);
		}
		printf("|\n");
	}
}

int main(){
	long int n,m,i,j;
	while(1){
		scanf("%ld %ld",&n, &m);
		if(n == 0 && m == 0)
			break;
		scanf("%d",&nW);
		int tabela[nW][2];
		
		for (i = 0; i < nW; ++i){
			scanf("%d %d",&tabela[i][0], &tabela[i][1]);
		}
		/*para [i,j] corresponder ao ponto inferior esquerdo da matriz na posicao [i,j]*/
		n++;
		m++;


		unsigned long t[n][m];

		for (i = 0; i < n; ++i){
			for (j = 0; j < m; ++j){
				t[i][j] = -1;
			}
		}
		
		unsigned long res = count(n,m,t,tabela);
		/*printVector(n,m,t);
		printf("res: %ld\n", res);*/
		if(res == 1)
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else if(res > 0)
			printf("There are %ld paths from Little Red Riding Hood's house to her grandmother's house.\n", res);
		else if(res == 0)
			printf("There is no path.\n");

	}
	return 0;
}