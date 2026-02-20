//0-1 knapsack 
#include<iostream>
#include<vector>
using namespace std;

int knapsackRec(vector<int> &val, vector<int> wt, int w, int n){        //O(2^n)
    if(n==0 || w==0) return 0;

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        //include
        knapsackRec(val, wt, w-itemWt, n-1) + itemVal;
        //exclude

        int ans2 = knapsackRec(val, wt, w, n-1);
        return max(knapsackRec(val, wt, w-itemWt, n-1) + itemVal, ans2);
    }else{
        return knapsackRec(val, wt, w, n-1);
    }
}

//memoization 
int knapsackMem(vector<int> &val, vector<int> wt, int w, int n, vector<vector<int>> &dp){      //O(n*w)
    if(n==0 || w==0) return 0;

    if(dp[n][w] !=-1) return dp[n][w];

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        //include
        int ans1 = knapsackMem(val, wt, w-itemWt, n-1, dp) + itemVal;
        //exclude

        int ans2 = knapsackMem(val, wt, w, n-1, dp);
        dp[n][w] = max(ans1, ans2);
    }else{
        dp[n][w] = knapsackMem(val, wt, w, n-1, dp);
    }
}

//tabulation
int knapsackTab(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}


int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int w =7;
    int n = 5;

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout<<knapsackMem(val, wt, w, n, dp)<<endl;

    return 0;
}