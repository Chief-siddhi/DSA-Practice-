//Maximum length chain of pairs 
// A pair (c,d) can come after pairs (a,b) if b<c
//Find the longest chain which can be formed from a given set of pairs

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    //ascending order of second element
    return p1.second<p2.second;
}
int maxChainLength(vector<pair<int, int>> pairs){
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);

    int ans = 1;
    int currEnd = pairs[0].second;

    for(int i=1; i<n; i++){
        if(pairs[i].first> currEnd){
            ans++;
            currEnd = pairs[i].second;
        }
    }
    cout<<"Max length of chain is: "<< ans << endl;
    return ans;
}
int main(){
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0,0));
    pairs[0]= make_pair(5,24);
    pairs[0]= make_pair(39,60);
    pairs[0]= make_pair(5,28);
    pairs[0]= make_pair(27,40);
    pairs[0]= make_pair(50,90);
    maxChainLength(pairs);
    return 0;
}

//we have used greedy appraoch with nlogn time complexity 