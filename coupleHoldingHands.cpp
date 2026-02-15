//couple holding hands- leetcode 765 
#include<iostream>
#include<vector>
using namespace std;
int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);

        // pos[x] = index of person x
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1;

            // already sitting together
            if (row[i + 1] == partner)
                continue;

            ans++;

            int partnerIndex = pos[partner];

            // swap row[i+1] with partner
            int second = row[i + 1];

            row[partnerIndex] = second;
            row[i + 1] = partner;

            // update positions
            pos[second] = partnerIndex;
            pos[partner] = i + 1;
        }

        return ans;
    }