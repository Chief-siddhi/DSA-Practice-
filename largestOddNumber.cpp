//largest odd number

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string largestOddNumber(string num){
    for(int i=num.length()-1; i>=0; i--){
        int digit = num[i]-'0';
        if(digit &1){
            return num.substr(0, i+1);
        }
    }
    return "";
}