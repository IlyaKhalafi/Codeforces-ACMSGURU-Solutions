#include <iostream>
#include <string>
using namespace std;
int flag[10];
int main(){
    int bull=0, cow=0;
    string a, b;
    cin>>a>>b;
    for(int i=0;i<4;i++){
        if(a[i]==b[i])
            bull++;
        else
            flag[a[i]-'0']++;
    }
    for(int i=0; i<4; i++){
        if(a[i]==b[i])
            continue;
        if(flag[b[i]-'0']>0){
            cow++;
            flag[b[i]-'0']--;
        }
    }
    printf("%d %d\n", bull, cow);
    return 0;
}
