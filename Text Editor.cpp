// https://codeforces.com/problemsets/acmsguru/problem/99999/397
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string text;cin>>text;int s;
    vector<char> out;vector<char> markup;
    for(int i=0;i<text.size();i++){
        if(text[i]!='L'&&text[i]!='R'){
            out.push_back(text[i]);
        }
        else if(text[i]=='L'&&out.size()>0){
markup.push_back(out.back());
out.pop_back();
        }
    else if(text[i]=='R'&&markup.size()>0){
out.push_back(markup.back());
markup.pop_back();
        }
    }
    if(out.size()==0&&markup.size()==0){cout<<""<<endl;return 0;}
    for(int i=0;i<out.size();i++){
        cout<<out[i];
    }
    s=markup.size();
    for(int i=0;i<s;i++){
        cout<<markup[s-1-i];
    }
    return 0;
}
