//Find all numbers disappeared in an array II 
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper){
    unordered_set<int>st;
    //step1: store all numbers 
    for(int x:nums){
        st.insert(x);
    }
    vector<vector<int>> ans;
    int start = -1;

    //step 2: check every number in [lower, upper]
    for(int x=lower; x<=upper; x++){
        //x is missing 
        if(st.find(x)==st.end()){
            if(start==-1){
                start=x;
            }
        }
        else{
            if(start !=-1){
                ans.push_back({start, x-1});
                start = -1;
            }
        }
    }
    //step 3: handle range that ends at upper
    if(start != -1){
        ans.push_back({start, upper});
    }
    return ans;
}


//another approach - sorting 
vector<vector<int>> findMissingRanges(vector<int>&nums, int lower, int upper){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    long long prev = (long long)lower -1;
    for(int x:nums){
        if(x<lower || x>upper){
            continue;
        }
        //missing range found
        if(x>prev+1){
            ans.push_back({
                (int)(prev+1),
                x-1
            });
        }
        //update previous number
        prev = max(prev, (long long)x);
    }
    //check missing numbers after last element
    if(prev<upper){
        ans.push_back({
            (int)(prev+1),
            upper
        });
    }
    return ans;
}
//time complexity - O(n log n)