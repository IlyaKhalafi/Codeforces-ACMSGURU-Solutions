#include <iostream>
using namespace std;
int n, t1, t2;
bool check(int num){
	return ( num + num*t1/t2 >= n );
}
int search(int l, int r){
	int mid = (l+r)/2;
	bool ans1 = check(mid), ans2 = check(mid-1);
	if( mid==0 || ( ans1 && !ans2 ))
		return mid;
	if( ans1 && ans2 )
		return search( l, mid );
	return search( mid, r );
}
int main(){
	scanf("%d%d%d", &n, &t1, &t2);
	int ans1 = search(0, 5001);
	swap(t1, t2);
	int ans2 = search(0, 5001);
	printf("%d %d\n", ans1 + ans2, max( ans2*t1, ans1*t2));
	return 0;
}
	
