#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
	int cor;
	int tamanho;
	int* nos_connected;
} no;

int max;

no * recebe_input(){
	int i, n_nos,par1,par2,ligacao;
	scanf("%d\n",&n_nos);
	scanf("%d\n",&ligacao);
	no* array;
	max = n_nos;
	array = (no*)malloc((n_nos)*sizeof(no));
	for(i = 0;i<n_nos;i++){
		array[i].cor = 0;
		array[i].numero = 0;
		array[i].tamanho = 0;	
		array[i].nos_connected = (int*)calloc(n_nos,sizeof(int));
	}
	for(i = 0;i<ligacao;i++){
		scanf("%d %d",&par1,&par2);
		array[par1].nos_connected[array[par1].tamanho] = par2;	
		array[par1].tamanho++;
		array[par1].numero = par1;
		array[par2].nos_connected[array[par2].tamanho] = par1;	
		array[par2].tamanho++;
		array[par2].numero = par2;
	}
	return array;

}


void dfs(no* array, int n){
	int i;
	array[n].cor = 1;
	for(i = 0 ;i<array[n].tamanho;i++){
		if(array[array[n].nos_connected[i]].cor == 0){
			dfs(array,array[n].nos_connected[i]);
		}
	}
	array[n].cor = 2;
}

int main(){
	no* array;
	array = recebe_input();
	int i = 0,j=0;
	while(i<max){
		if(array[i].cor==0){
			dfs(array,i);
			j++;
		}
		i++;
	}
	printf("%d\n", j);
	return 0;
}