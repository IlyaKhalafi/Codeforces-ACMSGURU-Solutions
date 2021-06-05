// https://codeforces.com/problemsets/acmsguru/problem/99999/347
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

bool check(string a, string b){
	return a+b < b+a;
}

int main()
{

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	crap;
	int n;
	cin>>n;
	string words[n];
	for(int i=0; i<n; i++)
		cin>>words[i];
	sort(words, words+n, check);
	for(int i=0; i<n; i++)
		cout<<words[i];
	cout<<endl;
	return 0;
}
