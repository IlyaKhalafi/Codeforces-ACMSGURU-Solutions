#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int maxn = 1e6+1;
bool prime[maxn];
int n, cnt;
vector<int> twin;
void sieve(){
	prime[1]=1;prime[0]=1;
	for(int i=2;i<=n;i++){
		if(prime[i])
			continue;
		for(int j=i+i;j<=n;j+=i)
			prime[j]=1;
		if(!prime[i-2]){
			twin.pb(i-2);
			cnt++;
		}
	}
}
int main(){
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n;
	sieve();
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;i++)
		cout<<2<<" "<<twin[i]<<"\n";
	return 0;
}
