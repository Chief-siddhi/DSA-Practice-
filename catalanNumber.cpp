//catalan' number
#include<iostream>
#include<vector>
using namespace std;

//using recursion
int catalanRec(int n){      //O(2^n)
    if(n==0 || n==1){
        return 1;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += catalanRec(i) * catalanRec(n-1-i);
    }
    return ans;
}
//by memoization
int catalanMem(int n, vector<int>& dp){  //O(n^2)
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += catalanMem(i, dp) * catalanMem(n-1-i, dp);
    }
    dp[n] = ans;
    return ans;
}
//by tabulation 
int catalanTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i;j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 4;
    vector<int> dp(n+1, -1);

    cout<< catalanRec(n) << endl;
    cout<< catalanMem(n, dp) << endl;
    cout<< catalanTab(n) << endl;
    return 0;
}