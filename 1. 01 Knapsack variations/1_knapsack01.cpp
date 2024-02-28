/*
    Given N items each having Weight Wi and Value Vi
    and Knapsack with capacity 'capacity', find the maximum profit
    after adding items into the knapsack without exceeding the capacity
*/
#include <bits/stdc++.h>
using namespace std;

#define ITEMS 102
#define CAPACITY 1002
int memoizedDP[ITEMS][CAPACITY]; 
int tabulationDP[ITEMS][CAPACITY];

int recursiveKnapsack01(vector<int>& weights, vector<int>& values, int capacity, int n) {
    if(capacity==0 || n==0) return 0;
    if(weights[n-1] <= capacity) {
        return max(
            values[n-1] + recursiveKnapsack01(weights, values, capacity-weights[n-1], n-1), 
            recursiveKnapsack01(weights, values, capacity, n-1)
        );
    } else {
        return recursiveKnapsack01(weights, values, capacity, n-1);
    }
}

int memoizedKnapsack01(vector<int>& weights, vector<int>& values, int capacity, int n) {
    if(n==0 || capacity==0) return 0;
    if(memoizedDP[n][capacity] != -1) return memoizedDP[n][capacity];
    if(weights[n-1] <= capacity) {
        memoizedDP[n][capacity] = max(
            values[n-1] + memoizedKnapsack01(weights, values, capacity-weights[n-1], n-1),
            memoizedKnapsack01(weights, values, capacity, n-1)
        );
    } else {
        memoizedDP[n][capacity] = memoizedKnapsack01(weights, values, capacity, n-1);
    }
    return memoizedDP[n][capacity];
}

int tabulationKnapsack01(vector<int>& weights, vector<int>& values, int capacity, int n) {
    for(int i=0; i<capacity+1; i++) 
        tabulationDP[0][i] = 0;
    for(int i=0; i<n+1; i++) 
        tabulationDP[i][0] = 0;
        
    for(int i=1; i< n+1; i++) { // n
        for(int j=1; j< capacity+1; j++) { // capacity
            if(weights[i-1] <= j) {
                tabulationDP[i][j] = max(values[i-1] + tabulationDP[i-1][j-weights[i-1]], tabulationDP[i-1][j]);
            } else tabulationDP[i][j] = tabulationDP[i-1][j];
        }
    }
    return tabulationDP[n][capacity];
}

int main() {
    vector<int> weights = {1, 3, 2, 4, 6 };
    vector<int> values = {1, 2, 5, 3, 4 };
    int N = 5, capacity = 12;
    memset(tabulationDP, -1, sizeof(tabulationDP));
    cout << "Max profit = " << tabulationKnapsack01(weights, values, capacity, N) << endl;
}