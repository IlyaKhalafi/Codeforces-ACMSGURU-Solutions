// This Code Uses backtrack to find a team for the specified situation
#include <iostream>
#include <vector>
#include <string>

#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int amo;
vector< pair<int, int> > dominos;
vector< pair<int, bool> > team;
bool used[100];   // for every domino, "0 means it is normal" and "1 means it is inversed"

void forward(int last, int pnt){    // We don't need last domino's index, we just need the last number of sequence
    if( pnt == amo )   // pnt is the index of vector that method is filling, "pnt == amo" means team is filled and ready
        return;

    for( int i = 0; i < amo; i++ ){

        if( used[i] )
            continue;

        if( dominos[i].x == last ){
            team.pb( mp(i, 0) );
            used[i] = 1;
            forward( dominos[i].y, pnt + 1 );
            if( team.size() == amo )
                return;
            used[i] = 0;
            team.pop_back();
        }

        if( dominos[i].y == last ){
            team.pb( mp(i, 1) );
            used[i] = 1;
            forward( dominos[i].x, pnt + 1 );
            if( team.size() == amo )
                return;
            used[i] = 0;
            team.pop_back();
        }
    }

}

int main(){
    int a;
    int b;
    cin >> amo; // Getting Data
    for( int i = 0; i < amo; i++ ){
        cin >> a >> b;
        dominos.pb( mp(a, b) );
    }

    for( int i = 0; i < amo; i++ ){

        if( team.size() == amo )
            break;

        team.pb( mp(i, 0) );  // Setting 'i' domino with normal situation
        used[i] = 1;
        forward( dominos[i].y, 1 );
        if( team.size() == amo )
            break;
        used[i] = 0;
        team.pop_back();

        team.pb( mp(i, 1) );  // Setting 'i' domino with inversed situation
        used[i] = 1;
        forward( dominos[i].x, 1 );
        if( team.size() == amo )
            break;
        used[i] = 0;
        team.pop_back();
    }

    if( team.size() == amo ){
        for( int i = 0; i < amo; i++){
            printf("%d ", team[i].x + 1);
            if( team[i].y )
                printf("-\n");
            else
                printf("+\n");
        }
    }
    else
        printf("No solution");

    return 0;
}
