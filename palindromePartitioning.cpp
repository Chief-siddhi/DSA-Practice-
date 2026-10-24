#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//check if substring s[l...r] is palindrome 
bool isPalindrome(string& s, int l, int r){
    while(l<r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve(string& s, int index, vector<string>& path, vector<vector<string>>& ans){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }
    //try every possible substring
    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){
            //choose
            path.push_back(s.substr(index, i-index+1));
            //explore remaining string
            solve(s, i+1, path, ans);
            //backtrack
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> path;
    solve(s,0, path,ans);
    return ans;
}