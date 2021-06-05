// https://codeforces.com/problemsets/acmsguru/problem/99999/523
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<int> path;
bool flag[101];
void check(int num){
	if( flag[num] )
		path.pb(num);
	flag[num]=0;
}
void pass(int a, int b){
	if(a<b)
		for(int i=a; i<=b; i++)
			check(i);
	else
		for(int i=a; i>=b; i--)
			check(i);
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int nums[n];
	for(int i=0; i<n; i++){
		scanf("%d", nums+i);
		flag[nums[i]]=1;
	}
	int l=m, r=m;
	for(int i=0; i<n; i++){
		if( !flag[nums[i]] )
			continue;
		if(nums[i] > r){
			pass(r, nums[i]);
			r=nums[i];
		}
		else if(nums[i] < l){
			pass(l, nums[i]);
			l=nums[i];
		}
	}
	int len = path.size();
	for(int i=0; i<len; i++)
		printf("%d ", path[i]);
	cout<<endl;
	return 0;
}
