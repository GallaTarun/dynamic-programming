/*
    Given an array 'coins', contains unique coin denominations
    and an integer 'sum'. Minimum number of coins from the given
    denominations, to form the given sum.
*/

#include<bits/stdc++.h>
using namespace std;

int recursiveMinCoins(vector<int>& coins, int sum, int n) {
    if(sum==0 || n==0) return (sum==0) ? 0 : INT_MAX;
    if(coins[n-1] <= sum) {
        return min(1+recursiveMinCoins(coins, sum-coins[n-1], n),  recursiveMinCoins(coins, sum, n-1));
    } else return recursiveMinCoins(coins, sum, n-1);
}

int memoizedMinCoins(vector<int>& coins, int sum, int n, vector<vector<int>>& dp) {
    if(sum==0 || n==0) return (sum==0) ? 0 : INT_MAX;
    if(dp[n][sum] != INT_MAX) return dp[n][sum];
    if(coins[n-1] <= sum) {
        return dp[n][sum] = min(1+ memoizedMinCoins(coins, sum-coins[n-1], n, dp), memoizedMinCoins(coins, sum, n-1, dp));
    } else return dp[n][sum] = memoizedMinCoins(coins, sum, n-1, dp);
}

int tabulationMinCoins(vector<int>& coins, int sum, int n) {
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++) dp[i][0] = 0;
    for(int i=1; i<sum+1; i++) dp[0][i] = INT_MAX;
    for(int i=1; i<n+1; i++) { // cur available coin denotions ending index
        for(int j=1; j<sum+1; j++) { // sum to be formed
            if(coins[i-1] <= j) {
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            } else dp[i][j] = dp[i-1] [j];
        }
    }
    return dp[n][sum];
}

int main() {
    vector<int> coins = {1, 2,  3};
    int n = coins.size(), sum = 5;
    // vector<vector<int>> dp(n+1, vector<int>(sum+1, INT_MAX));
    cout << "Min coins needed to achieve sum k = " << tabulationMinCoins(coins, sum, n);
    return 0;   
}