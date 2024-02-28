/*
    Given an array 'coins', contains unique coin denominations
    and an integer 'sum'. Find the number of ways in which the Given
    'sum' can be obtained using the denominations. There are infinite 
    coins and each coin can be repeated any no.of times.
*/

#include<bits/stdc++.h>
using namespace std;

int recursiveNumWays(vector<int>& coins, int sum, int n) {
    if(sum==0 || n==0) return (sum==0) ? 1 : 0;
    if(coins[n-1] <= sum) {
        return recursiveNumWays(coins, sum-coins[n-1], n) + recursiveNumWays(coins, sum, n-1);
    } else return recursiveNumWays(coins, sum, n-1);
}

int memoizedNumWays(vector<int>& coins, int sum, int n, vector<vector<int>>& dp) {
    if(sum==0 || n==0) return (sum==0) ? 1 : 0;
    if(dp[n][sum] != -1) return dp[n][sum];
    if(coins[n-1] <= sum) {
        return dp[n][sum] = memoizedNumWays(coins, sum-coins[n-1], n, dp) + memoizedNumWays(coins, sum, n-1, dp);
    } else return dp[n][sum] = memoizedNumWays(coins, sum, n-1, dp);
}

int tabulationNumWays(vector<int>& coins, int sum, int n) {
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++) dp[i][0] = 1;
    for(int i=0; i<sum+1; i++) dp[0][i] = (i==0);
    for(int i=1; i<n+1; i++) { // cur available coin denotions ending index
        for(int j=1; j<sum+1; j++) { // sum to be formed
            if(coins[i-1] <= j) {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    vector<int> coins = {1, 2,  3};
    int n = coins.size(), sum = 5;
    // vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    cout << "No.of ways to achieve sum k = " << tabulationNumWays(coins, sum, n);
    return 0;   
}