/*
    Given two strings a and b, return the length of 
    longest common subsequence in both the strings.
*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b, int m, int n) {
    if(m==0 || n==0) return 0;
    if(a[m-1] == b[n-1]) return longestCommonSubsequence(a, b, m-1, n-1);
    return max(longestCommonSubsequence(a, b, m, n-1), longestCommonSubsequence(a, b, m-1, n));
}

int tabulationLongestCommonSubsequence(string a, string b, int m, int n) {
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
    return dp[m][n];
}

int main() {
    string a = "abcde", b = "abfcebcd";
    int m = a.size(), n = b.size();
    
    cout << "length of longest common subsequence = " << tabulationLongestCommonSubsequence(a, b, m, n) << endl;
    return 0;
}