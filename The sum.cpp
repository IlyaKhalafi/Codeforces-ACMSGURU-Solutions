#include <iostream>
using namespace std;
typedef unsigned long long int ull;
int main(){
	int n;
	cin>>n;
	ull ans=0, a=1, b=1;
	for(int i=1;i<=n;i++){
		ans+=a;
		b+=a;
		a=b-a;
	}
	cout<<ans;
	return 0;
}
