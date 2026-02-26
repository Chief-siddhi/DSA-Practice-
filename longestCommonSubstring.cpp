//longest common substring
//substring is a contiguous sequence of characters within a string

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonSubstring(int n, int m, string str1, string str2){ //O(n*m)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main(){
    string str1, str2;
    cout<<"Enter first string: ";
    cin>>str1;
    cout<<"Enter second string: ";
    cin>>str2;

    int n = str1.size();
    int m = str2.size();

    cout<<"Length of longest common substring is: "<<longestCommonSubstring(n, m, str1, str2)<<endl;

    return 0;
}