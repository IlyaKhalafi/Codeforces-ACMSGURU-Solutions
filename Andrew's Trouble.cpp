#include <iostream>
using namespace std;
int lims[4] = {0, 299, 899, 1799};
int main()
{
	int s, p, cnt=0;
	scanf("%d%d", &s, &p);
	for(int i=0; i<4; i++)
		if(p-s>lims[i])
			cnt++;
	printf("%d\n", cnt);
	return 0;
}
