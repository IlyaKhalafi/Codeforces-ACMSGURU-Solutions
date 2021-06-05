#include <iostream>
#include <cmath>
using namespace std;

int fact(int m, int k){
	if(m==1)return k;
	int out=1, p=k, cnt;
	for(int i=2;i<=k/2 && p>1;i++){
		if(p%i==0){
			cnt=0;
			while(p%i==0){
				cnt++;
				p/=i;
			}
			out*=pow(i,(cnt+m-1)/m);
		}
	}
	if(out==1)
		return k;
	return out;
}

int main(){
	int n, m, k, x;
	scanf("%d%d%d", &n, &m, &k);
	int val = fact(m,k), cnt=0;
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		if(x%val==0)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
