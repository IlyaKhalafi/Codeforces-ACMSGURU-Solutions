// https://codeforces.com/problemsets/acmsguru/problem/99999/130
#include <iostream>
using namespace std;
typedef long long int ll;
ll comb[61][31];
void bio(int n, int k){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=k && j<=i; j++){
			if( i==j || j==0 )
				comb[i][j]=1;
			else
				comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
}
int main(){
	int n;
	scanf("%d", &n); 
	bio( 2*n, n);
	printf("%lld %d\n", comb[n*2][n]/(n+1), n+1);
	return 0;
}
