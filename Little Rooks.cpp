#include <iostream>
using namespace std;
int bio(int n,int k){
	if(k==0 || k==n)
		return 1;
	return bio(n-1,k-1)+bio(n-1,k);
}
int main(){
	int n ,k;
	unsigned long long int ans=1;
	cin>>n>>k;
	if(k>n){
		cout<<0<<endl;
		return 0;
	}
	for(int i=n;i>n-k;i--)
		ans*=i;
	ans*=bio(n,k);
	cout<<ans<<endl;
	return 0;
}
