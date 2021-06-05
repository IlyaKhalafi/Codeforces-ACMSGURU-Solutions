#include <iostream>
using namespace std;
int main(){
	int val[3], nd[3], best = INT_MAX;
	for(int i=0;i<3;i++)
		scanf("%d", val+i);
	for(int i=0;i<3;i++)
		scanf("%d", nd+i);
	for(int i=0;i<3;i++)
		best= min(best, val[i]/nd[i]);
	printf("%d", best);
	return 0;
}
