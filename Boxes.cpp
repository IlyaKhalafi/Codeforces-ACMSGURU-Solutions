// https://codeforces.com/problemsets/acmsguru/problem/99999/126
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

int count(int a, int b, int cnt){
	if( !a || !b )
		return cnt;

	if( a > b )
		return count(a-b, b*2, cnt+1);
	else
		return count(a*2, b-a, cnt+1);
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	crap;
	int a, b;
	cin >> a >> b;

	int num = (a+b) / __gcd(a, b);
	while( num % 2 == 0 )
		num /= 2;

	if( num > 1 )
		cout << -1 << endl;
	else
		cout << count(a, b, 0) << endl;

    return 0;
}
