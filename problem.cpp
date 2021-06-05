#include <iostream>
using namespace std;

void multi( int amo ){
    cout << 9;
    for( int i = 0; i < amo-1; i++ )
        cout << 0;
}

int main(){
    int digits = 0;
    cin >> digits;

    if( digits < 9 ){
        cout << 0;
    }
    if(  digits == 9 ){
        cout << 1;
    }
    if( digits > 9 ){
        multi( digits - 9 );
    }
    return 0;
}
