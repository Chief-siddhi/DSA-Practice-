#include<iostream>
using namespace std;
//find permutations
//find and print all permutations(arrangements) of a given string

void permutations(string str, string ans){

    int n=str.size();
    if(n==0){
        cout<<ans<<"\n";
        return;
    }
    for(int i=0; i<str.size();i++){
        char ch=str[i];
        string nextStr = str.substr(0,i)+str.substr(i+1,n-i-1);
        permutations(nextStr,ans+ch);//ith char choice to add in prem 
    }
}
int main(){
    string str ="abc";
    string ans="";
    permutations(str,ans);
    return 0;
}