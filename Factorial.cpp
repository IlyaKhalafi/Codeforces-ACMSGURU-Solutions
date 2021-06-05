#include <iostream>
using namespace std;
int fact(int num){
	int out=num;
	while(num>=5){
		num/=5;
		out+=num;
	}
	return out;
}
int search(int l,int r, int val){
	int mid = (l+r)/2;
	if(fact(mid)==val)
		return mid;
	else if(l>=r)
		return -1;
	else if(fact(mid)<val)
		return search(mid+1, r, val);
	else
		return search(l, mid, val);
}
int main(){
	int n;
	scanf("%d", &n);
	if(n==0){
		cout<<1<<endl;
		return 0;
	}
	long long int ans = search(0,2*1e8,n);
	if(ans==-1)
		cout<<"No solution"<<endl;
	else
		cout<<5*ans<<endl;
	return 0;
}
