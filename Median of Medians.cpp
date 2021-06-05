#include <iostream>
#include <algorithm>
using namespace std;
int scanf(){
	int k[3];
	for(int i=0;i<3;i++)
		scanf("%d", k+i);
	sort(k, k+3);
	return k[1];
}
int main(){
	int mid[3];
	for(int i=0;i<3;i++)
		mid[i]=scanf();
	sort(mid,mid+3);
	cout<<mid[1];
	return 0;
}
