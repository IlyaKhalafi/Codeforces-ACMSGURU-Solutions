// https://codeforces.com/problemsets/acmsguru/problem/99999/297
#include <iostream>
using namespace std;
int main(){
	int n, m, x, s=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d", &x);
		s+=x;
	}
	printf("%d\n", s%n);
	return 0;
}
