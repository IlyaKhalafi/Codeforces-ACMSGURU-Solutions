#include <iostream>
#include <string>
using namespace std;
string conv(string word){
    int last = word.size()-1;
    if(word[last]=='x' || word[last]=='s' || word[last]=='o' || ( word[last]=='h' && word[last-1]=='c'))
        word+="es";
    else if( word[last]=='y' ){
        word[last]='i';
        word+="es";
    }
    else if( word[last]=='f'){
        word[last]='v';
        word+="es";
    }
    else if(word[last]=='e' && word[last-1]=='f'){
        word[last-1]='v';
        word+="s";
    }
    else
        word+='s';
    return word;
}
int main(){
    int n;
    cin>>n;
    string p;
    for(int i=0;i<n;i++){
        cin>>p;
        cout<<conv(p)<<'\n';
    }
    return 0;
}
