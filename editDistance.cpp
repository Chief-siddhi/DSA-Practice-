//edit distance 
//for 2 strings, return min no of operations to convert str1 to str2

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base cases
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }

        // Fill DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    dp[i][j] = 1 + min({
                        dp[i][j-1],     // Insert
                        dp[i-1][j],     // Delete
                        dp[i-1][j-1]    // Replace
                    });
                }
            }
        }
        return dp[n][m];
    }