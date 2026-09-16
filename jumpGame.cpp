#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums){
    int maxIndex = 0;

    for(int i=0; i<nums.size(); i++){
        if(i>maxIndex){
            return false;
        }
        maxIndex = max(maxIndex, i+nums[i]);
    }
    return true;
}
//time complexity - O(N)
//space complexity - O(1)