/*
    Given an array 'arr' and a sum 'k', find the count of subsets 
    of 'arr' which has sum 'k'
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 101
#define SUM 1001

int memoizedDp[SIZE][SUM];
int tabulationDp[SIZE][SUM];

int recursiveSubsetsSumCount(vector<int>& arr, int sum, int n) {
    if(sum==0 || n==0) return (sum==0);
    if(arr[n-1] <= sum) {
        return recursiveSubsetsSumCount(arr, sum-arr[n-1], n-1) + recursiveSubsetsSumCount(arr, sum, n-1);
    }
    return recursiveSubsetsSumCount(arr, sum, n-1);
}

int memoizedSubsetSumCount(vector<int>& arr, int sum, int n) {
    if(sum==0 || n==0) return sum==0;
    if(memoizedDp[n][sum] != -1) return memoizedDp[n][sum];
    if(arr[n-1] <= sum) {
        return memoizedDp[n][sum] = memoizedSubsetSumCount(arr, sum-arr[n-1], n-1) + memoizedSubsetSumCount(arr, sum, n-1);
    } else return memoizedDp[n][sum] = memoizedSubsetSumCount(arr, sum, n-1);
}

int tabulationSubsetSumCount(vector<int>& arr, int sum, int n) {
    for(int i=0; i<n+1; i++) tabulationDp[i][0] = 1;
    for(int i=1; i<sum+1; i++) tabulationDp[0][i] = 0;
    
    for(int i=1; i<n+1; i++) { // i = cur n
        for(int j=1; j<sum+1; j++) { // j = cur sum
            if(arr[i-1] <= j) 
                tabulationDp[i][j] = tabulationDp[i-1][j-arr[i-1]] + tabulationDp[i-1][j];
            else tabulationDp[i][j] = tabulationDp[i-1][j];
        }        
    }
    return tabulationDp[n][sum];
}


int main() {
    vector<int> arr = {2,3,5,6,8,10};
    int k = 10, n=6;
    int res = tabulationSubsetSumCount(arr, k, n);
    cout << "Count of subsets with sum k = " << res << endl;
    return 0;
}