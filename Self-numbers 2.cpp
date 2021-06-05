// https://codeforces.com/problemsets/acmsguru/problem/99999/108
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

int add_digs(int num){
	int temp = num;
	while( temp ){
		num += temp % 10;
		temp /= 10;
	}
	return num;
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	crap;
	
	int high, n;
	cin >> high >> n;

	bool flag[high+1] = {0};
	vector<int> self_nums;
	for(int i = 1; i <= high; i++){

		if( !flag[i] )
			self_nums.push_back(i);

        if( add_digs(i) <= high )
            flag[ add_digs(i) ] = 1;
	}

	cout << self_nums.size() << endl;
	int temp;
	for(int i = 0; i < n; i++){
		 cin >> temp;
		 cout << self_nums[temp-1] << " ";
	}
	cout << endl;

    return 0;
}
