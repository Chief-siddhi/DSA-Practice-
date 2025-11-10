//eetCode 3542 — "Minimum Operations to Convert All Elements to Zero", using a monotonic stack (O(n) time, O(n) space)

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        stack<int>s;
        s.push(0);
        for(int num:nums){
            while(!s.empty() && s.top()>num) s.pop();
            if(s.empty() || s.top()<num){
                ++ans;
                s.push(num);
            }
        }
        return ans;
    }
};