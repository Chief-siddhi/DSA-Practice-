//leetode 1046
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int lastStoneWeights(vector<int>& stones){
    priority_queue<int> pq;
    for(int s: stones){
        pq.push(s);
    }
    while(pq.size() > 1){
        int y = pq.top(); pq.pop();
        int x = pq.top(); pq.pop();

        if(y != x){
            pq.push(y-x);
        }
    }
    return pq.empty() ? 0 :pq.top();
}