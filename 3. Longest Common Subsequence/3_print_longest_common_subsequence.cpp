/*
    Given two strings a and b, return the  
    longest common subsequence in both the strings.
*/

#include<bits/stdc++.h>
using namespace std;

string tabulationLongestCommonSubsequence(string a, string b, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    stack<char> s;
    int i=m, j=n;
    while(i>0 && j>0) {
        if(a[i-1] == b[j-1]) {
            s.push(a[i-1]);
            i--, j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) 
                i--;
            else j--;
        }
    }
    string res = "";
    while(!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int main() {
    string a = "abcded", b = "abfdcebc";
    int m = a.size(), n = b.size();
    
    cout << "longest common subsequence = " << tabulationLongestCommonSubsequence(a, b, m, n) << endl;
    return 0;
}