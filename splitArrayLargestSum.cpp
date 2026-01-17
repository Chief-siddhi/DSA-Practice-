#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    long long mn = INT_MIN;
    long long mx = 0;
    long long ans = 0;

    // Find search space
    for (int x : nums) {
        mx += x;
        mn = max(mn, (long long)x);
    }

    while (mn <= mx) {
        long long mid = mn + (mx - mn) / 2;

        int parts = 1;
        long long sum = 0;

        for (int x : nums) {
            sum += x;
            if (sum > mid) {
                parts++;
                sum = x;
            }
        }

        if (parts <= k) {
            ans = mid;
            mx = mid - 1;
        } else {
            mn = mid + 1;
        }
    }
    return ans;
}
