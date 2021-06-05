#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define point pair<int ,int>
using namespace std;

int n, d;
vector<point> bank;
bool check_y(int a, int b){return bank[a].y >= bank[b].y;}
bool check_x(int a, int b){return bank[a].x >= bank[b].x;}
int main(){
	scanf("%d%d", &n, &d);
	int a, b;
	int dis[n], val[n];
	for(int i=0; i<n; i++){
		scanf("%d%d", &a, &b);
		dis[i]=i; val[i]=i;
		bank.pb(mp(a,b));
	}
	sort(dis, dis+n, check_x);
	sort(val, val+n, check_y);
	int high_l=0, high_r=0, l=0, r=0, best=-1, b1=-1, b2=-1;
	for(int i=0; i<n && r<n; i++){
		if( bank[high_l].y < bank[i].y )
			high_l = i;
		while( bank[l].x+d < bank[r].x && r<n)
			r++;
		if( r==n )
			continue;
		while( idx[ high_r ] < r )
			high_r++;
		if( bank[high_l].y + bank[idx[high_r]].y > best){
			best = bank[high_l].y + bank[idx[high_r]].y;
			b1=high_l+1; b2=idx[high_r]+1;
		}
		cout<<b1<<' '<<b2<<endl;
	}
	printf("%d %d\n", b1, b2);
	return 0;
}
