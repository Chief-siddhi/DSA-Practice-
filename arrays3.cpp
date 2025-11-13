//Given an integer array nums,find a subarray that has the largest product,and return the product.The testcases are generated so that the answer will fit in a 32-bit integer

#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> &nums){
    int maxTillNow = nums[0];
    int minTillNow = nums[0];
    int ans = maxTillNow;

    for(int i=1; i<nums.size(); i++){
        int curr = nums[i];
        int tempMaxTillNow = max(curr, maxTillNow*curr, minTillNow*curr);
        minTillNow = min(curr, min(maxTillNow*curr, minTillNow*curr));
        maxTillNow = tempMaxTillNow;

        ans = max(maxTillNow, ans);
    }
    return ans;
}
