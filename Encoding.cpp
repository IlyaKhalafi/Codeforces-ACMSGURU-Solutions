// https://codeforces.com/problemsets/acmsguru/problem/99999/175
#include <iostream>
using namespace std;

int search( int l, int r, int n ){
	if( l==r )
		return n;
	int mid = (r+l-1)/2;
	if( n<=mid )
		return search( r-mid+l, r, r-n+l);
	else
		return search( l, r-mid+l-1, l+r-n); 
}

int main(){
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d\n", search( 1, n, p ));
	return 0;
}
