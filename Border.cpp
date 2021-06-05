// https://codeforces.com/problemsets/acmsguru/problem/99999/133
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define endl "\n"
typedef long long int ll;

int main(){
	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	crap;
	int n;
	cin >> n;

	int A[n], B[n];
	for(int i = 0; i < n; i++)
		cin >> A[i] >> B[i];

	pair<int, int> pairt[n];

    for (int i = 0; i < n; i++)
    {
        pairt[i].first = A[i];
        pairt[i].second = B[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        A[i] = pairt[i].first;
        B[i] = pairt[i].second;
    }

	stack<int> grt;

	int cnt = 0;
	for(int i = 0; i < n; i++){
		while(!grt.empty() && grt.top() < B[i])
			grt.pop();
		if( grt.size() > 0 )
			cnt++;
		grt.push(B[i]);
	}

    cout << cnt << endl;

    return 0;
}
