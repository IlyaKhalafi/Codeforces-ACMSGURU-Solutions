// https://codeforces.com/problemsets/acmsguru/problem/99999/127
#include <iostream>
#include <string>
using namespace std;

int nums[10];

int main(){
	cin.tie(0);
	int k, n;
	string num;
	cin >> k >> n;
	for(int i=0; i<n; i++){
		cin >> num;
		nums[ num[0] - '0' ]++;
	}
	int ans = 2;
	for(int i=0; i<10; i++)
		ans += (nums[i] + k-1 ) / k;
	cout << ans << endl;
	return 0;
}
