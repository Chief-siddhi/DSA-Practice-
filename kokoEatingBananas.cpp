#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long hoursNeeded(vector<int>& piles, int k) {
    long long hours = 0;

    for (int p : piles) {
        hours += (p + k - 1) / k;
    }

    return hours;
}

int minEatingBananas(vector<int>& piles, int h) {
    int lo = 1;
    int hi = *max_element(piles.begin(), piles.end());

    int ans = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (hoursNeeded(piles, mid) <= h) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum eating speed: "
         << minEatingBananas(piles, h) << endl;

    return 0;
}