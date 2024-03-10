/*
    Given two strings a and b, return the length  
    of the shortest possible string, that contains a and b 
    as subsequences. (Shortest Common SuperSequence)
    
    ---> solution = len(a) + len(b) - LCS(a, b) 
        LCS(a, b) => Longest common subsequence of a, b
*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else {
                if(a[i-1] == b[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

// new solution
int shortestCommonSupersequence(string a, string b, int m, int n) {
    if(m == 0) return n;
    if(n == 0) return m;
    if(a[m-1] == b[n-1]) return 1 + shortestCommonSupersequence(a, b, m-1, n-1);
    return 1 + min(shortestCommonSupersequence(a, b, m-1, n), shortestCommonSupersequence(a, b, m, n-1));
}

int main() {
    string a = "aggtab", b = "gxtxayb";
    int m = a.size(), n = b.size();
    cout << "Length of shortest common supersequence = " << m + n - longestCommonSubsequence(a, b, m, n) << endl;
    return 0;
}