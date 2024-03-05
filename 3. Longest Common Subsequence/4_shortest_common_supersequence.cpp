/*
    Given two strings a and b, return the length length 
    of the shortest possible string, that contains a and b 
    as subsequences. (Shortest Common SuperSequence)
    
    ---> solution = len(a) + len(b) - LCS(a, b) 
        LCS(a, b) => Longest common subsequence of a, b
*/

#include<bits/stdc++.h>
using namespace std;

// recursive LCS ==> TODO: can optimize this further to O(n^2)
int longestCommonSubsequence(string a, string b, int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(a[m-1] == b[n-1]) return 1 + longestCommonSubsequence(a, b, m-1, n-1);
    return max(longestCommonSubsequence(a, b, m-1, n), longestCommonSubsequence(a, b, m, n-1));
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