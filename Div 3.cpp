#include <iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	printf("%d", (n/3)*2 +(n%3==2));
	return 0;
}
