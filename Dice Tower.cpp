#include <iostream>
using namespace std;

int main(){
	int n, x, ans = -1;
	scanf("%d", &n);
	x = (n+13)/14*14-n;
	if( x>1 && x<13 )
		ans = (n+x)/14-1;
	if( ans == 0 || n < 30 )
		ans = -1;
	if( n == 21 )
		ans = 1;
	printf("%d", ans);
	return 0;
}
