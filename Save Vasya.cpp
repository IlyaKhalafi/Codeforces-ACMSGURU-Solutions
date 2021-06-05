#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

string bio[21][21]; // bio[n][k];

string bigsum(string str1, string str2) { 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
   
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
   
    if (carry) 
        str.push_back(carry+'0'); 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

void build_bio(int size){
	for(int i = 0; i <= size; i++){
		for(int j = 0; j <= i; j++){

			if( i == j || j == 0 )
				bio[i][j] = "1";

			else
				bio[i][j] = bigsum( bio[i-1][j], bio[i-1][j-1] );

		}
	}
}

string bigmul(string num1, string num2) { 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    	return "0"; 
  
    vector<int> result(len1 + len2, 0); 
    int i_n1 = 0, i_n2 = 0;  
      
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;  
                        
        for (int j=len2-1; j>=0; j--) 
        {  
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;  
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
  
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        i_n1++; 
    } 
  
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    if (i == -1) 
    	return "0"; 
  
   	string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 

string bigpow(string num, int pow){
	if( !pow )
		return "1";

	if( pow % 2 )
		return bigpow( big );

	return bigpow( bigmul(num, num), pow/2 );
}

string itos(int num){
	string out = "";
	while( num ){
		out += (num % 10) + '0';
		num /= 10;
	}
	reverse(out.begin(), out.end());
	return num;
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif
	crap;

	int a, b, k;
	cin >> a >> b >> k;
	build_bio(k);

	string sum = "0";
	for(int i = 0; i <= k; i++)
		sum += bio[k][i] * pow(b, k-i) * pow(a, i);

	cout << sum << endl;

    return 0;
}
