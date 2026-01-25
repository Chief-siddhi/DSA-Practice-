//Sliding window maximum
//maximum of all subarrays of size k
//we have a given a k of some size lets say k=3
// we have to imagine a window of 3 numbers starting from first element and the window will proceed further 
//for example if we have 1,2,3,4,5,6,7,8,9,10 and k=3
//the window will be 1,2,3 so from this we have to choose the max of this window and print in ans 
//the window will proceed further and next window will be 2,3,4 then choose the max element from this and print and so on...
//we will use priority queue for this question and will build a mwx Heap
//this question can be solved using deque for O(n) time complexity

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int slidingWindow(vector<int> arr, int K){
    priority_queue<pair<int, int>> pq;

    for(int i=0; i<K; i++){
        pq.push(make_pair(arr[i], i));
    }
    cout<<"output: "<< pq.top().first<<" ";

    for(int i=K; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i-K)){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<pq.top().first<< " ";
    }
    cout<<endl;

}

int main(){
    vector<int> arr={1,3,-1,-3,5,3,6,7};
    int K = 3;
    slidingWindow(arr,K);

    return 0;
}
