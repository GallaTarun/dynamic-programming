/*
    Given an array 'arr', return the minimum difference of
    sum of two partitons of the 'arr'
    -> divide arr into 2 partitions, sum each partition, return
    return the minimum difference of the possible sums of partitions
*/

#include<bits/stdc++.h>
using namespace std;

int minimumSubsetSumDiff(vector<int>& arr, int sum, int n) {
    // subset sum k variation
    bool dp[n+1][sum+1];
    for(int i=0; i<sum+1; i++) dp[0][i] = (i==0);
    for(int i=0; i<n+1; i++) dp[i][0] = true;
    for(int i=1; i<n+1; i++) { // i = cur no.of elements
        for(int j=1; j<sum+1; j++) { // j = cur required sum
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=sum/2; i>=0; i--) {
        if(dp[n][i] && dp[n][sum-i]) {
            if(i*2 == sum) return 0;
            else return abs(sum - 2*i);
        } 
    }
    return 0;
}

int main() {
    vector<int> arr = { 1, 5, 6, 11 };
    int res = minimumSubsetSumDiff(arr, accumulate(arr.begin(), arr.end(), 0), arr.size());
    cout << "Minimum subset sum difference = " << res << endl;
    return 0;
}




 


