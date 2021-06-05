// https://codeforces.com/problemsets/acmsguru/problem/99999/172
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int n, m, cnt, nums[201];
bool flag;
vector<int> vert[201];
void pass(int v, int p){
	if(nums[v]!=p && nums[v]!=-1)
		flag=1;
	else
		nums[v]=p;
	cnt+=1-p;
	if(flag)
		return;
	int len=vert[v].size();
	for(int i=0; i<len; i++)
		if(nums[ vert[v][i] ] == nums[v])
			flag=1;
	for(int i=0; i<len; i++)
		if(nums[ vert[v][i] ] == -1)
			pass(vert[v][i], 1-p);
}
int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	cin >> n >> m;
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		if(a==b)
			flag=1;
		vert[a].pb(b);
		vert[b].pb(a);
	}
	for(int i=1; i<=n; i++)
		nums[i] = -1;
	for(int i=1; i<=n; i++)
		if(nums[i]==-1)
			pass(i,0);
	if(flag)
		cout << "no";
	else{
		cout << "yes\n" << cnt << endl;
		for(int i=1; i<=n; i++)
			if(nums[i]==0)
				printf("%d ", i);
	}
	cout<<endl;
	return 0;
}
