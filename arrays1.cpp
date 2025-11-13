//Given an integer array nums return ture if any value appears atleast twice in an array and return false if every element is distinct
#include<iostream>
#include<vector>
#include <unordered_set>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int> &nums){
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++){
        if(nums[i-1] == nums[i]){
            return true;
        }
    }
    return false;
}