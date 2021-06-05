#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

const int size = 15010;

double cors[size], p[size];

double sum(int n, double station){
	double out = 0;
	forn(i, n)
		out += abs(station - cors[i]) * p[i];
	return out;
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	forn(i, n)
		cin >> cors[i] >> p[i];

	double right = *max_element(cors, cors+n);
	double left = *min_element(cors, cors+n);
	double mid = (right+left)/2;
	double mid_left, mid_right;

	do{
		mid_left = sum( n, (left+mid)/2 );
		mid_right = sum( n, (mid+right)/2 );
		if( mid_right < mid_left ){
			left = mid;
			mid = (mid+right)/2;
		}
		else{
			right = mid;
			mid = (left+mid)/2;
		}

	}while( abs( mid_left - mid_right ) < 0.000001 );

	//cout << mid << " : " << sum(n, mid) << endl;
	//cout << "3.000" << " : " << sum(n, 3) << endl;
	printf("%llf : %llf\n", mid, sum(n, mid));
	printf("3.000000 : %llf", sum(3, mid));

    return 0;
}
