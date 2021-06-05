#include <iostream>
#include <string>
using namespace std;

string reverse(string str)
{
    string out = "";
   for ( int i = str.length() - 1; i >= 0; i-- )
        out += str[i];
    return out;
}

int main(){
    int amo, sum, move;
    cin >> amo >> sum;

    if( sum == 0 && amo == 1 ){
        cout << "0 0";
        return 0;
    }

    if( sum < 1 || sum > 9 * amo ){
        cout << "-1 -1";
        return 0;
    }

    int minx = sum-1;
    string low = "";
    int maxx = sum;
    string high = "";
    for( int i = 0; i < amo; i++ ){
        move = min( 9, maxx);
        maxx -= move;
        high += char( '0' + move );

        move = min( 9, minx);
        minx -= move;
        low += char( '0' + move );
    }

    low = reverse(low);

    if( low[ 0 ] == '0' )
        low[ 0 ] = '1';
    else
        low[ 0 ] = char( low[ 0 ] + 1 );

    cout << low << " " << high;
    return 0;
}
