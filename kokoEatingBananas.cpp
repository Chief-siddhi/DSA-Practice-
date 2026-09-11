#include<iostream>
#include<vector>

using namespace std;

int minEatingBananas(vector<int> &piles, int h ){
    int lo = 1, hi  = *max_element(piles.begin(), piles.end());
    int ans = hi;
    
    while(lo <= high){
        mid = lo+(hi-lo)/2;
        
        if(hoursNeeded(piles,mid)<=h){
            ans= mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return ans;
}
private:
    long long hoursNeeded(vector<int>&piles, int k){
        long long hours =0;
        for(int p:piles){
            hours += (p+k-1)/2;
        return hours;
        }
    }