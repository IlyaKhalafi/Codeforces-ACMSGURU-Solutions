#include <iostream>
#include <algorithm>
using namespace std;

int pr[100], del[100], ans[100], n;

void scan(int *arr){
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
}

bool check( int a, int b){
	if( pr[a] == pr[b] )
		return del[a] >= del[b];
	return pr[a] >= pr[b];
}

int main(){
	scanf("%d", &n);
	scan(pr); scan(del);
	
	for(int i=0; i<n; i++)
		ans[i] = i;
	sort( ans, ans+n, check);
	
	int start = 0, end = 0;
	for(int i=0; i<n; i++){
		start += pr[ ans[i] ];
		end = max( end, start + del[ ans[i] ]);
	}
	printf("%d\n", end);
	return 0;
}
