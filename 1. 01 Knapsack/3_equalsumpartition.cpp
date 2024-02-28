/*
    Given an array 'arr' and a sum 'sum', find if the array can be partitioned
    into two subsets having equal sum. 
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 102
#define SUM 1002
bool memoizedDp[SIZE][SUM];
bool tabulationDp[SIZE][SUM];

bool recursiveEqualSumPartition(vector<int>& arr, int sum, int n) {
    if(n==0) return sum == 0;
    if(arr[n-1] <= sum) {
        return recursiveEqualSumPartition(arr, sum-arr[n-1], n-1) || recursiveEqualSumPartition(arr, sum, n-1);
    } else return recursiveEqualSumPartition(arr, sum, n-1);
}

bool memoizedEqualSumPartition(vector<int>& arr, int sum, int n) {
    if(n==0) return sum==0;
    if(memoizedDp[n][sum]) {
        return memoizedDp[n][sum];
    }
    if(arr[n-1] <= sum) {
        memoizedDp[n][sum] = memoizedEqualSumPartition(arr, sum-arr[n-1], n-1) || memoizedEqualSumPartition(arr, sum, n-1);
    } else memoizedDp[n][sum] = memoizedEqualSumPartition(arr, sum, n-1);
    return memoizedDp[n][sum];
}

bool tabulationEqualSumPartition(vector<int>& arr, int sum, int n) {
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
    vector<int> arr = { 3, 5, 3, 2, 7, 2, 8 };
    int n = 5, sum = accumulate(arr.begin(), arr.end(), 0);
    bool res = (sum%2==0) ? tabulationEqualSumPartition(arr, sum/2, n) : false;
    cout << "Has Equal sum partition = " << res << endl;
    return 0;
}