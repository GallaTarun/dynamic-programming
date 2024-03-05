/*
    Given two strings a and b, return the length of 
    longest common substring in both the strings.
*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string a, string b, int m, int n, int curMax) {
    if(m==0 || n==0) return curMax;
    if(a[m-1] == b[n-1]) return longestCommonSubstring(a, b, m-1, n-1, curMax+1);
    return max(longestCommonSubstring(a, b, m, n-1, 0), longestCommonSubstring(a, b, m-1, n, 0));
}

int tabulationLongestCommonSubstring(string a, string b, int m, int n) {
    int dp[m+1][n+1];
    int res = 0;
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    string a = "abcde", b = "abfcdebcde";
    int m = a.size(), n = b.size();
    
    cout << "length of longest common substring = " << tabulationLongestCommonSubstring(a, b, m, n) << endl;
    return 0;
}