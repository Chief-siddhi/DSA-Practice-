//span = max no of consecutive days(including current) for which price<=today's price
// we are given stocks=[100,80,60,70,60,85,100]
//we will check for the previous days prices and check how many days the price was less than or equal to the current day's price 
//for 100-> span 1
//for 80-> span 1
//for 60-> span 1
//for 70-> span 2 (60,70)
//for 60-> span 1
//for 85-> span 4 (70,60,85)
//for 100-> span 6 (85,60,70,60,80,100)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0]=1;

    for(int i=1; i<stock.size(); i++){
        int currPrice = stock[i];

        while(!s.empty() && currPrice>= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        } else{
            int prevHigh = s.top();
            span[i]  = i-prevHigh;
        }
    }
    for(int i=0; i<span.size(); i++){
        cout<<span[i]<<" ";
    }    
    cout<<endl;
}
int main(){
    vector<int> stack = {100,80,60,70,60,85,100};
    vector<int> span = {0,0,0,0,0,0,0};

    stockSpanProblem(stack,span);
    return 0;
}