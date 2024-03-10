/*
    Given 2 strings 'a' and 'b', return the min number of insertions
    and deletions needed to make a and b strings similar.
    
    Solution:
    - Let lcs_len = length of longest subsequence of A and B. 
        m = LEN(A), n = Len(B)
    - no need to change characters of the LCS.
    - characters in A which are not part of LCS are to 
      be removed from a, and characters in B, which are 
      not part of LCS, are to be inserted.
    => result = (m - lcs_len) + (n - lcs_len) = (m + n - 2 * lcs_len)
                ~~~~~~~~~~~~~   ~~~~~~~~~~~~~
                  deletions       insertions
*/

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string a = "heap", b = "pea";
    int m = a.size(), n = b.size();
    cout << "Min no.of ins/del to make a and b similar = " << m + n - 2 * lcs(a, b, m, n) << endl;
    return 0;
}