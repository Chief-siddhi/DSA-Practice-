#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//recursion 
int mcmRec(vector<int> arr, int i, int j){
    if(i==j){
        return 0;
    }
    int ans= INT_MAX;

    for(int k=i; k<j; k++){
        //(i,k)
        int cost1= mcmRec(arr, i, k);

        //(k+1, j)
        int cost2 = mcmRec(arr, k+1, j);

        //curr partition cost
        int currCost = cost1+cost2+(arr[j-1]*arr[k]*arr[j]);
        ans = min(ans, currCost);
    }
    return ans;
}

//memoization
int mcmMemo(vector<int> arr, int i, int j, vector<vector<int>>& dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans= INT_MAX;

    for(int k=i; k<j; k++){
        //(i,k)
        int cost1= mcmMemo(arr, i, k, dp);

        //(k+1, j)
        int cost2 = mcmMemo(arr, k+1, j, dp);

        //curr partition cost
        int currCost = cost1+cost2+(arr[j-1]*arr[k]*arr[j]);
        ans = min(ans, currCost);
    }
    return ans;
}

//by tabulation 
int mcmTab(vector<int> arr){
    int n= arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));

    //initialization
    for(int i=1; i<n; i++){
        dp[i][i]=0;
    }
    //bottom up fill
    for(int len=2; len<n; len++){
        for(int i=1; i<n-len; i++){
            int j=i+len-1;

            for(int k=i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
                dp[i][j] = min(dp[i][j], currCost);

            }
        }
    }
    return dp[1][n-1];
}
int main(){
    vector<int> arr={1,2,3,4,3};
    int n=arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<mcmMemo(arr,1,n-1,dp)<<endl;
    cout<<mcmTab(arr)<<endl;
    return 0;
}