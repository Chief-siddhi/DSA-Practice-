//Count Subarrays with even odd ratio 1
#include<iostream>
#include<vector>
using namespace std;

int countRatioSubarrays(vector<int> &nums, int a, int b){
    int n = nums.size(), valid_subarray=0;
    for(int i=0; i<n; i++){
        int x=0, y=0;
        for(int j=i; j<n; j++){
            if(nums[j]%2 == 0) x++;
            else y++;
            if(y>0 && x*b <= y*a) valid_subarray++;
        }
    }
    return valid_subarray
}