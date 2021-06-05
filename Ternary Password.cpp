// https://codeforces.com/problemsets/acmsguru/problem/99999/546
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

int n, cnt[3], goal[3], change[3], change_count;

char rec(char c){
	if( change[ c - '0' ] >= 0 )
		return c;
	
	forn(i, 3){
		if( change[i] > 0 ){
			change[i]--;
			change[c-'0']++;
			change_count++;
			return i + '0';
		}
	}
	return c;
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	crap;
	cin >> n;
	cin >> goal[0] >> goal[1];
	goal[2] = n - goal[0] - goal[1];

	string pass;
	cin >> pass;

	forn(i, n)
		cnt[ pass[i] - '0' ]++;

	forn(i, 3)
		change[i] = goal[i] - cnt[i];

	forn(i, n)
		pass[i] = rec(pass[i]);

	if( change[0] != 0 || change[1] != 0 || change[2] != 0 )
		cout << -1 << endl;
	else
		cout << change_count << endl << pass << endl;

    return 0;
}
