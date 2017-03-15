#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

double best;

void calculateDistances(int nPlaces, double distances[][nPlaces], int places[][2]){
	int i,j;
	for (i = 0; i < nPlaces; ++i){
		for (j = 0; j < nPlaces; ++j){
			
			distances[i][j] = sqrt(pow(places[i][0]-places[j][0],2)+pow(places[i][1]-places[j][1],2));		

		}
	}
	

}

int sum(int nPlaces, int visit[nPlaces]){
	int i,c=0;
	for (i = 0; i < nPlaces; ++i){
		c+=visit[i];
	}
	return c;
}


void shortestPath(int v, double len, int nPlaces, double distances[][nPlaces], int visit[nPlaces]){
	int i;
	if(len >= best)
		return;

	if(sum(nPlaces, visit) == nPlaces && (len < best || best==0)){
		best = len;
		return;
	}

	for ( i = 0; i < nPlaces; ++i){
			
		if(visit[i] == 0){
			visit[i] = 1;
			len +=distances[v][i];
			if(len<=best)
				shortestPath(i,len,nPlaces,distances,visit);
			
			len -=distances[v][i];
			visit[i] = 0;
		}
	
	}
}

void printVector(int n, double t[][n]){
	int i,j;
	for (i = 0; i <n; i++){
		for (j = 0; j < n; ++j){
			printf("|%lf", t[i][j]);
		}
		printf("|\n");
	}
}

int main(){
	int nPlaces,i,j;

	scanf("%d",&nPlaces);

	int places[nPlaces][2];

	for (i = 0; i < nPlaces; ++i){
		scanf("%d %d",&places[i][0], &places[i][1]);
	}

	best=10000000;
	int v[nPlaces];
	memset(v,0,sizeof(v));
	double distances[nPlaces][nPlaces];
	calculateDistances(nPlaces,distances,places);
	for (j = 0; j < nPlaces; ++j){
		v[j] = 1;
		shortestPath(j,0,nPlaces,distances,v);
		v[j] = 0;
	}

	printf("%.3f\n",best);
	

	return 0;
}