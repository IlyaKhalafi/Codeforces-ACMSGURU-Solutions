#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,m;
	cin.tie(0);
	cin>>m>>n;
	string phrase[n];
	for(int i=0;i<n;i++)
		cin>>phrase[i];
	cout<< phrase[ (m-1)%n ];
	return 0;
}
