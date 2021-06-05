// https://codeforces.com/problemsets/acmsguru/problem/99999/355
#include <iostream>
using namespace std;
const int maxn = 1e4+1;
int nums[maxn], n, high=1;;

void sieve(){
	for(int i=1; i<=n; i++)
		nums[i] = i;
	for(int i=2; i<=n; i++)
		if( nums[i] == i )
			for(int j=i*i; j<=n; j+=i)
				nums[j] = min( nums[j], i );
	for(int i=2; i<=n; i++){
		if( nums[i] == i)
			nums[i] = 2;
		else
			nums[i] = nums[ i / nums[i] ] + 1;
		high = max( high, nums[i] );
	}
}

int main(){
	scanf("%d", &n);
	sieve();
	printf("%d\n", high);
	for(int i=1; i<=n; i++)
		printf("%d ", nums[i]);
	cout<<'\n';
	return 0;
}
