// https://codeforces.com/problemsets/acmsguru/problem/99999/302
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int len;
stack<int> pass;

char uppercase(char c){
	if( c >= 'A' && c <= 'Z' )
		return c;
	return char(c + 'A' - 'a');
}
char lowercase(char c){
	if( c >= 'a' && c <= 'z' )
		return c;
	return char(c + 'a' - 'A');
}
int manage(int val){
	if( pass.empty() ){
		pass.push(val);
		return val%2;
	}
	if( val % pass.top() || val == pass.top() ){
		pass.push( val );
		return val%2;
	}
	else if( val % pass.top() == 0 )
		pass.pop();
	if( !pass.empty() )
		return pass.top()%2;
	return -1;
}

string sum(string word){
	string out = "", pure;
	for(int i=0; i<len; i++){
		if( word[i] == '<' ){
			i++;
			pure = "";
			while( word[i] != '>' ){
				pure+= word[i];
				i++;
			}
			if( pure == "UP" )
				out += '2';
			else if( pure == "/UP" )
				out += '4';
			else if( pure == "DOWN" )
				out += '3';
			else
				out += '9';
		}
		else
			out += word[i];
	}
	return out;
}

int main(){
	string word, ans="";
	cin>>word;
	len = word.size();
	word = sum(word);
	len = word.size();
	
	int pos = -1;
	for(int i=0; i<len; i++){
		if( word[i] >= '0' && word[i] <= '9' ){
			pos = manage( word[i] - '0' );
			continue;
		}
		if( pos == -1 )
			ans += word[i];
		else if( pos == 0 )
			ans += uppercase( word[i] );
		else
			ans += lowercase( word[i] );
	}
	cout<<ans<<endl;
	return 0;
}
