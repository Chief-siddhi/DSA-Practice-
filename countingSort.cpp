//use a frequency count of elements from min to max 

#include<iostream>
#include<climits>
using namespace std;

void countSort(int arr[], int n){
    int freq[100000] ;
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    for(int i=minVal, j=0; i<=maxVal; i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]--;
        }
    }

}