//https://codeforces.com/problemsets/acmsguru/problem/99999/111
#include <bits/stdc++.h>
using namespace std;

#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i=0; i<n; i++)
#define endl "\n"
typedef long long int ll;

string bigmul(string num1, string num2){ 
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

string bigdiv(string number, int divisor) { 
    string ans = ""; 
  
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
  
    while (number.size() > idx) {
        ans += (temp / divisor) + '0'; 
   
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
  
    if (ans.length() == 0) 
        return "0"; 
  
    return ans; 
} 

int isSmaller(string str1, string str2){
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return 1;
    if (n2 < n1)
        return -1;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return 1;
        else if (str1[i] > str2[i])
            return -1;
    return 0;
}


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

string bin_search(string low, string high, string num){
	string mid = bigdiv( bigsum(low, high), 2 );
	
	if(isSmaller(bigmul(mid, mid), num) != -1 && isSmaller(bigmul(bigsum(mid, "1"), bigsum(mid, "1")), num) == -1 )
		return mid;

	if(isSmaller(bigmul(mid, mid), num) == -1)
		return bin_search(low, mid, num);
	else if(isSmaller(bigmul(mid, mid), num) == 1)
		return bin_search(mid, high, num);

	return "invalid";
}

int main(){

	// Please erase or ignore this part...
	#ifndef ONLINE_JUDGE
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/input.txt", "r", stdin);
	    freopen("E:/Programming Projects/C++ Projects/Editor Files/output.txt", "w", stdout);
	#endif

	string num;
	cin >> num;

	string low = "1";

	cout << bin_search(low, num, num);
    
    return 0;
}
