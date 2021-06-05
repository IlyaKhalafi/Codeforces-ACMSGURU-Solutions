// https://codeforces.com/problemsets/acmsguru/problem/99999/116
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e4+1;
bool prime[maxn];
int val[maxn], len;
vector<int> super, fact;

void sieve(int n){
	int cnt = 1; prime[1] = 1;
	for(int i=2; i<=n; i++){
		if( prime[i] )
			continue;
		if( !prime[cnt] ){
			super.push_back(i);}
		cnt++;
		for(int j=i*i; j<=n; j+=i)
			prime[j] = 1;
	}
	len = super.size();
}

void knapsack(int n){
	for(int i=0; i<len; i++){
		for(int j=0; j+super[i] <= n; j++){
			if( val[j] || j==0 ){
				if( val[ j+super[i] ] )
					val[ j+super[i] ] = min( val[ j+super[i] ], val[j]+1 );
				else
					val[ j+super[i] ] = val[j] + 1;
			}
		}
	}
}

void rec(int n){
	if( n==0 )
		return;
	if( val[n] == 1 ){
		fact.push_back( n );
		return;
	}
	for(int i=0; i<len ; i++){
		if( val[ n-super[i] ] == val[n]-1 ){
			fact.push_back( super[i] );
			rec( n - super[i] );
			break;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	sieve(n);
	knapsack(n);
	if( val[n] == 0 ){
		printf("%d\n", 0);
	}
	else{
		printf("%d\n", val[n] );
		rec(n);
		while(!fact.empty()){
			printf("%d ", fact.back());
			fact.pop_back();
		}
	}
	return 0;
}
