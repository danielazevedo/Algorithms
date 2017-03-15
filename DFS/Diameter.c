#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
	int cor;
	int tamanho;
	int* nos_connected;
} no;

int max, maior_caminho;
int nUltimo;

no * recebe_input(){
	int i, n_nos,par1,par2;
	scanf("%d\n",&n_nos);
	no* array;
	max = n_nos;
	array = (no*)malloc((n_nos+1)*sizeof(no));
	for(i = 1;i<=n_nos;i++){
		array[i].cor = 0;
		array[i].numero = i;
		array[i].tamanho = 0;	
		array[i].nos_connected = (int*)calloc(n_nos,sizeof(int));
	}
	for(i = 1;i<n_nos;i++){
		scanf("%d %d",&par1,&par2);
		array[par1].nos_connected[array[par1].tamanho] = par2;	
		array[par1].tamanho++;
		array[par2].nos_connected[array[par2].tamanho] = par1;	
		array[par2].tamanho++;
	}
	return array;

}


void dfs(no* array, int n, int size){
	int i;
	size++;
	array[n].cor = 1;
	for(i = 0 ;i<array[n].tamanho;i++){
		if(array[array[n].nos_connected[i]].cor == 0){
			dfs(array,array[n].nos_connected[i],size);
		}
	}
	array[n].cor = 2;
	
	if(size > maior_caminho){
		maior_caminho= size;
		nUltimo = n;
	}

}

int main(){
	maior_caminho = 0;
	no* array;
	array = recebe_input();
	
	int i = 1,j= 1;
	
	
	dfs(array,i,0);
	j=1;
	while(j<=max){
		array[j].cor = 0;
		j++;
	}
	dfs(array,nUltimo,0);

	i++;
	maior_caminho--;
	printf("%d\n", maior_caminho);
	return 0;
}