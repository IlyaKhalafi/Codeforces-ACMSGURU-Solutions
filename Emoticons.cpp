// https://codeforces.com/problemsets/acmsguru/problem/99999/538
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string word;
	vector<int> par;
	getline( cin, word);
	int len = word.size();
	bool pos = 0;
	for( int i=0; i<len; i++ ){
		if(word[i]=='-' || word[i]==':' || word[i]==',' || word[i]==';' )
			pos = 0;
		else if( word[i] == '(' ){
			par.push_back(1);
			pos = 1;
		}
		else if( word[i] == ')' && pos ){
			par.pop_back();
			pos = 0;
		}
		else if( word[i] == ')' ){
			par.push_back(0);
		}
	}
	len = par.size();
	printf("%d\n", len);
	return 0;
}
