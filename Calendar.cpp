#include <iostream>
using namespace std;

int mon[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if( n > mon[m]-mon[m-1]){
		printf("Impossible\n");
		return 0;
	}
	int day = n + mon[m-1];
	if( day % 7 )
		printf("%d\n", day%7);
	else
		printf("%d\n", 7);
	return 0;
}
