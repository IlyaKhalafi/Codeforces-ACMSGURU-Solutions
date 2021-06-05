#include <iostream>
using namespace std;
const int maxn = 4*1e4;
bool prime[maxn];
void sieve(){
	for(int i=2; i*i<maxn; i++)
		if(!prime[i])
			for(int j=i*i; j<maxn; j+=i)
				prime[j]=1;
}
bool fact(int num){
	if(num < maxn)
		return !prime[num];
	else
		for(int i=2; i*i<=num; i++)
			if(num%i==0)
				return 0;
	return 1;
}
bool check(int num){
	for(int i=2; i*i<=num; i++)
		if(!prime[i] && num%i==0 && fact(num/i))
			return 1;
	return 0;
}
int main(){
	int n, x;
	scanf("%d", &n);
	sieve();
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		if(check(x))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
