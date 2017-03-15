#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int numero;
	int cor;
	int tamanho;
	int* nos_connected;
} no;

no * recebe_input(int n_nos, int ligacao){
	int i,par1,par2;

	no* array;
	array = (no*)malloc((n_nos+1)*sizeof(no));
	for(i = 0;i<n_nos+1;i++){
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

void BFS(no* array, int i, int n_nos){
	int queue[n_nos+1];
	int pos_queue = 0,ele,j;
	array[i].cor = 1;
	queue[pos_queue] = array[i].numero;
	pos_queue++;
	while(pos_queue){
		ele = queue[pos_queue-1];
		pos_queue--;
		for(j = 0;j<array[ele].tamanho;j++){
			if(array[ele].cor == 1){
				if(array[array[ele].nos_connected[j]].cor==0){
					array[array[ele].nos_connected[j]].cor =2;
					queue[pos_queue] = array[array[ele].nos_connected[j]].numero;
					pos_queue++;
				}
				else if(array[array[ele].nos_connected[j]].cor==1){
					printf("NO\n");
					return;
				}
			}else {
				if(array[array[ele].nos_connected[j]].cor==0){
					array[array[ele].nos_connected[j]].cor =1;
					queue[pos_queue] = array[array[ele].nos_connected[j]].numero;
					pos_queue++;
				}
				else if(array[array[ele].nos_connected[j]].cor==2){
					printf("NO\n");
					return;
				}
			}
		}
	}
	printf("YES\n");
}

int main(){
	int n_nos, ligacao;
	while(scanf("%d %d\n",&n_nos,&ligacao)==2){

		no* array = recebe_input(n_nos,ligacao);
		BFS(array, 1, n_nos);
	}

	return 0;
}
