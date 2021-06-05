#include <iostream>
#include <cmath>
using namespace std;
const int lim=1e6+1;
int cnt[lim];
int main(){
	int n, x, maxn=0;
	scanf("%d", &n);
	int nums[n];
	for(int i=0;i<n;i++){
		scanf("%d", nums+i);
		maxn= max(maxn, nums[i]);
	}
	for(int i=0;i<n;i++){
		int x= sqrt(nums[i]);
		for(int j=1;j<=x;j++){
			if(nums[i] % j==0){
				cnt[j]++;
				if(nums[i] % j != j)
					cnt[nums[i]/j]++;
			}
		}
	}
	for(int i=maxn;i>=1;i--){
		if(cnt[i]>1){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
