//  https://codeforces.com/problemsets/acmsguru/problem/99999/344
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif
	crap;

	int n, m;
	cin >> n >> m;
	int cells[n][m];
	queue< pair<int, int> > weeds;

	char cell;
	forn(i, n)
		forn(j, m){
			cin >> cell;
			if( cell == '.' )
				cells[i][j] = 0;
			else if( cell == 'X' ){
				cells[i][j] = 2;
				weeds.push(make_pair(i, j));
			}
		}

	int ans = 0;
	int x, y;
	while( !weeds.empty() ){
		ans++;
		x = weeds.front().first;
		y = weeds.front().second;
		weeds.pop();
		for (int z1 = -1 ; z1 <= 1 ; z1++){
            for (int z2 = -1 ; z2 <= 1 ; z2++){

                if (abs(z1)+abs(z2)!=1)
                    continue;
                
                int xx = x+z1 , yy = y+z2;
                
                if (xx>=0 && n>xx && yy>=0 && m>yy){
                    cells[xx][yy]++;
                    
                    if ( cells[xx][yy] == 2 )
                        weeds.push(make_pair(xx,yy));                    
            	
            	}
    		}	
    	}
	}
	
	cout << ans << endl;

    return 0;
}
