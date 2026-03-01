#include<iostream>
#include<vector>
#include<string>    
using namespace std;
    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        // Initialize first row (empty string case)
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            } else {
                dp[0][j] = false;
            }
        }

        // Fill DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(t[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }

