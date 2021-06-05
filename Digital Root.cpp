#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forn(i, n) for(int i=0; i<n; i++)
typedef long long int ll;

int dig_root(ll x){
	if( x % 9 || !x )
		return x % 9;
	return 9;
}

ll get(int amo){
	int num;
	cin >> num;

	if( !amo )
		return dig_root(num);

	return dig_root(dig_root(num) * dig_root(get(amo-1)) + num);
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	int k;
	cin >> k;

	forn(i, k){
		int n;
		cin >> n;
		cout << get(n-1) << endl;
	}

    return 0;
}
