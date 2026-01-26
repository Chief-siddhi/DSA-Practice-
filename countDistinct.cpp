//we have to count distinct elements
//we will use a set as it stores distinct elements only 
//we will store the count of these elements also 

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int> arr){
    unordered_set<int> s;

    for(int i=0; i<arr.size(); i++){
        s.insert(arr[i]);
    }
    for(int el:s){
        cout<<el<<" ";
    }
    cout<<endl;
    return s.size();
}

int main(){
    vector<int> arr={4,3,2,5,6,7,3,4,2,1};
    cout<<"count"<<countDistinct<<endl;

    return 0;
}