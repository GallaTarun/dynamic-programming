/*
    Given an array and a sum, find if the array has a subarray
    with specified sum.
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 102
#define SUM 1002
bool memoizedDp[SIZE][SUM];
bool tabulationDp[SIZE][SUM];

bool recursiveHasSubsetSum(vector<int>& arr, int sum, int n) {
    if(n==0) return sum == 0;
    if(arr[n-1] <= sum) {
        return recursiveHasSubsetSum(arr, sum-arr[n-1], n-1) || recursiveHasSubsetSum(arr, sum, n-1);
    } else return recursiveHasSubsetSum(arr, sum, n-1);
}

bool memoizedHasSubsetSum(vector<int>& arr, int sum, int n) {
    if(n==0) return sum==0;
    if(memoizedDp[n][sum]) {
        return memoizedDp[n][sum];
    }
    if(arr[n-1] <= sum) {
        memoizedDp[n][sum] = memoizedHasSubsetSum(arr, sum-arr[n-1], n-1) || memoizedHasSubsetSum(arr, sum, n-1);
    } else memoizedDp[n][sum] = memoizedHasSubsetSum(arr, sum, n-1);
    return memoizedDp[n][sum];
}

bool tabulationHasSubsetSum(vector<int>& arr, int sum, int n) {
    for(int i=0; i<n+1; i++) tabulationDp[i][0] = true;
    for(int i=1; i<sum+1; i++) tabulationDp[0][i] = false;
    
    for(int i=1; i<n+1; i++) { // n
        for(int j=1; j<sum+1; j++) { // sum
            if(arr[i-1] <= j) 
                tabulationDp[i][j] = tabulationDp[i-1][j-arr[i-1]] || tabulationDp[i-1][j];
            else tabulationDp[i][j] = tabulationDp[i-1][j];
        }
    }
    
    return tabulationDp[n][sum];
}

int main() {
    vector<int> arr = { 2, 3, 7, 6, 10 };
    int sum = 11, n = 5;
    
    cout << "Has subset sum = " << tabulationHasSubsetSum(arr, sum, n) << endl;
    return 0;
}