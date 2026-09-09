#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N-> kitna max food mil skta h
//S-> kitne din k liye survive krna h
//M-> kitna food mujhe survive krne k liye chahiye 
int minimumDays(int S, int N, int M){
    int sunday = S/7;

    int buyDays = S-sunday;
    int totalFood = S*M;
    int ans = 0;

    if(totalFood % N== 0){
        ans =  totalFood /N;
    }
    else{
        ans = totalFood /N +1;
    }
    if(ans<=buyDays){
        return ans;
    }
    else{
        return -1;
    }
   
}