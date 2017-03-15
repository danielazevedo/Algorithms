#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <algorithm> 

using namespace std;

int count,nCoins;
int change;
	
vector< vector<int> > possibilities;



bool checkPossibility(vector <int> v){
	unsigned int i;
	sort (v.begin(),v.end());
	for (i = 0; i < possibilities.size(); ++i){
		if(possibilities[i] == v)
			return false;
	}
	return true;
}
void printVetor(vector< vector<int> > T){
	int i,j;
	for (i = 0; i < nCoins; ++i){
		for (j = 0; j < change; ++j){
			
			printf("|%d", T[i][j]);
		}
		printf("|\n");
	}
}


int makeChange(int i, int c, vector< vector<int> > &T, vector <int> d, vector <int> v){
	if(c == 0){
		if(checkPossibility(v)){
			sort (v.begin(),v.end());
			possibilities.push_back(v);
			return 1;
		}
		else{
			return 0;
		}
		
	}

	if(i == 0 && c != 0)
		return 0;

	if(d[i] > c){
		T[i][c] = makeChange(i-1,c,T,d,v);
	}
	else{
		T[i][c] = makeChange(i-1,c,T,d,v);
		v.push_back(d[i]);
		T[i][c] += makeChange(i-1,c-d[i],T,d,v);
	}

	return T[i][c];

}




int main(){

	int nTestCases,i,j;
	scanf("%d",&nTestCases);
	for (i = 0; i < nTestCases; ++i){
		scanf("%d %d",&change, &nCoins);
		change++;
		nCoins++;
		vector <int> coins(nCoins, 0);

		vector< vector<int> > T(nCoins, vector<int>(change,0));
		

		coins[0] = 0;
		for (j = 1; j < nCoins; ++j){
			scanf("%d",&coins[j]);
		
		}
		vector <int> v;
		int res = makeChange(nCoins-1,change-1,T,coins,v);
		/*printVetor(T);*/
		printf("%d\n", res);
		

	}


	return 0;
}