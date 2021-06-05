#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
bool flag[51];
bool gr(int a,int b){return a>=b;}
int main(){
	int n, s, p, v;
	scanf("%d%d", &n, &s);
	vector<int> vert[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d", &p);
		for(int j=0;j<p;j++){
			scanf("%d", &v);
			vert[i].pb(v);
		}
	}
	int len = vert[s].size();
	flag[s]=1;
	for(int i=0;i<len;i++)
		flag[vert[s][i]]=1;
	vector<int> ans;
	for(int i=0;i<len;i++){
		int keep=vert[vert[s][i]].size();
		for(int j=0;j<keep;j++){
			if(!flag[ vert[ vert[s][i] ][j] ]){
				ans.pb(vert[ vert[s][i] ][j]);
				flag[ vert[ vert[s][i] ][j] ]=1;
			}
		}
	}
	sort(ans.begin(), ans.end(), gr);
	cout<<ans.size()<<endl;
	while(!ans.empty()){
		printf("%d ", ans.back());
		ans.pop_back();
	}
	return 0;
}
