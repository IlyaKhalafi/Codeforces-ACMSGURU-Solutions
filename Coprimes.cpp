#include <iostream>
using namespace std;
int sieve(int n){
	int out = n;
	for(int i=2;i*i<=n;i++){
		if(n%i)
			continue;
		out-=out/i;
		while(n%i==0)
			n/=i;
	}
	if(n>1)
		out-=out/n;
	return out;
}
int main(){
	int n;
	scanf("%d",&n);
	cout<<sieve(n)<<"\n";
	return 0;
}
