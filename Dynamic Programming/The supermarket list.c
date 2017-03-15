#include <stdio.h>
#include <stdlib.h>


typedef struct{
	unsigned int weight;
	unsigned int price;
}object;


/*restricao 1 - numero de objetos*/
/*restricao 2 - nao passar um determinado budget*/
/*pretendemos maximizar o peso*/

int nObjects, maxObjects;
unsigned int budget;

void printVector(int n, int m, int v[][m]){
	int i,j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			printf("|%d ", v[i][j]);
		}
		printf("|\n");
	}
}


unsigned int max(unsigned int a, unsigned int b){
	if(a > b)
		return a;

	return b;

}



unsigned int knapsackTopDown(int i, int currentObj, unsigned int b, object objects[nObjects], int T[][budget]){
	if(i == 0){
		return 0;
	}
	
	if(T[i][b] >= 0)
		return T[i][b];
	/*printf("%d\n", nObjects-i-1);*/

	if(currentObj > maxObjects){
		return 0;
	}

	if(objects[i].price > b){
		T[i][b] = knapsackTopDown(i-1,currentObj,b,objects,T);
	}
	else{
		T[i][b]=max(knapsackTopDown(i-1, currentObj, b,objects,T), objects[i].weight + knapsackTopDown(i-1, currentObj+1, b-objects[i].price,objects,T) );
	}
	return T[i][b];
}


int main(){

	int k=0, i, j;
	unsigned int res=0;
	

	scanf("%d",&nObjects);
	scanf("%d",&maxObjects);
	scanf("%d",&budget);
	budget++;
	object objects[nObjects];
	int T[nObjects][budget];
	for (i = 0; i < nObjects; ++i){
		for (j = 0; j < budget; ++j){
			T[i][j] = -1;
		}
	}
	for (k = 0; k < nObjects; ++k){
		scanf("%d %d",&objects[k].weight, &objects[k].price);
	}
	res = knapsackTopDown(nObjects-1, 0, budget-1, objects, T);
	printf("%d\n", res);
	/*printVector(nObjects,budget,T);*/

	return 0;
}