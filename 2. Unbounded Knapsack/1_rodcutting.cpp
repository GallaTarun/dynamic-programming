/*
    Given a rod of length N, array 'lengths' and 'prices', where
    prices[i] is the cost of cutting a piece of rod of length lengths[i],
    You can cut the rod any number of times. 
    find the maximum possible cost that could be acheived.
*/

#include<bits/stdc++.h>
using namespace std;

int recursiveRodCuttingMaxCost(vector<int>& len, vector<int>& prices, int N, int index) {
    if(index==-1 || N==0) return 0;    
    if(len[index] <= N) {
        return max(prices[index] + recursiveRodCuttingMaxProfit(len, prices, N-len[index], index), recursiveRodCuttingMaxProfit(len, prices, N, index-1));
    } else return recursiveRodCuttingMaxProfit(len, prices, N, index-1);
}

int memoizedRodCuttingMaxProfit(vector<int>& len, vector<int>& prices, int N, int index, vector<vector<int>>& dp) {
    if(index==-1 || N==0) return 0;
    if(dp[N][index] != -1) return dp[N][index];
    if(len[index] <= N) {
        return dp[N][index] = max(prices[index] + memoizedRodCuttingMaxProfit(len, prices, N-len[index], index, dp), memoizedRodCuttingMaxProfit(len, prices, N, index-1, dp));
    } else {
        return dp[N][index] = memoizedRodCuttingMaxProfit(len, prices, N, index-1, dp);
    }
}

int tabulationRodCuttingMaxProfit(vector<int>& len, vector<int>& prices, int N) {
    int dp[N+1][N+1];
    for(int i=1; i<N+1; i++) 
        dp[i][0] = prices[i-1];        
    for(int i=0; i<N+1; i++) 
        dp[0][i] = 0;
    for(int i=1; i<N+1; i++) { // cur len of rod 
        for(int j=1; j<N+1; j++) { // len of partition to be cur from the rod
            if(j <= i) {
                dp[i][j] = max(prices[j-1] + dp[i-len[j-1]][j], dp[i][j-1]);
            } else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[N][N];
}

int main() {
    vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8}, prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << "Max price acheived = " << tabulationRodCuttingMaxProfit(lengths, prices, n);
    return 0;   
}