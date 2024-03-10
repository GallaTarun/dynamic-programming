/*
    Given two strings a and b, return the shortest possible 
    string, that contains a and b as subsequences. 
    (Shortest Common SuperSequence)
    
    ---> solution = len(a) + len(b) - LCS(a, b) 
        LCS(a, b) => Longest common subsequence of a, b
*/

#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string a, string b, int m, int n) {
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
    string res = "";
    int i=m, j=n;
    while(i!=0 && j!=0) {
        if(a[i-1] == b[j-1]){
            res = a[i-1] + res;
            i--, j--;
        }
        else {
            if(dp[i-1][j] < dp[i][j-1]) {
                res = b[j-1] + res;
                j--;
            } else {
                res = a[i-1] + res;
                i--;
            } 
        }
    }
    while(i>0) res = a[--i] + res;
    while(j>0) res = b[--j] + res;
    return res;
}

int main() {
    string a = "aggtab", b = "gxtxayb";
    int m = a.size(), n = b.size();
    cout << "Shortest common supersequence = " << longestCommonSubsequence(a, b, m, n) << endl;
    return 0;
}