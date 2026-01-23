//next permutation
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermuattion(vector<int>& A){
    int n=A.size();
    int pivot=-1;
    //step1->pivot
    for(int i=n-2; i>=0; i++){
        if(A[i]<A[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        reverse(A.begin(), A.end());
        return;
    }
    //step2 -> find the next larger element to swap with pivot
    for(int i=n-1; i>pivot; i--){
        if(A[i]>A[pivot]){
            swap(A[i], A[pivot]);
            break;
        }
    }
    //step3-> reverse thes suffix
    reverse(A.begin()+pivot+1, A.end());
}