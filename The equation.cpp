#include <stdio.h>

int main(){

    int a, b, c, x1, x2, y1, y2;

    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &x1, &x2, &y1, &y2);

    int cnt = 0;

    for( int i = x1; i <= x2; i++)
        if( 0-(a*i+c)/b >= y1 && 0-(a*i+c)/b <= y2 )
            cnt++;

    printf("%d", cnt);

    return 0;
}
