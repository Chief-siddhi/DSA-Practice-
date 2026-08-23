//Check ASCII palindromic 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindromic(string s){
    string binary = "";

    //convert every character to 8-bit binary 
    for(char c:s){
        for(int i=7; i>=0; i++){
            binary += ((c>>i)&1) + '0';
        }
    }
    //checl if binary string is palindrome 
    int left=0;
    int right = binary.length()-1;

    while(left<right){
        if(binary[left] != binary[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}