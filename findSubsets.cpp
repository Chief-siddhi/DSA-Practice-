//find and print all subsets fo a given string

#include<iostream>
using namespace std;
//this will be solved by recursion and backtracking 
//at every index we have two choices either to include the character or not to include the character
//so we will make two recursive calls for every index

void printSubsets(string str, string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    char ch=str[0];

    //yes choice
    printSubsets(str.substr(1, str.size()-1), subset+ch);
    //no choice
    printSubsets(str.substr(1, str.size()-1), subset);
}

int main(){
    string str="abc";
    string subset="";
    printSubsets(str, subset);
    return 0;
}