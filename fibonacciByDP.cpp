//fibonacci by DP 
#include<iostream>
#include<vector>
using namespace std;

int fib(int n){
    if(n==0 || n==1) return n;

    return fib(n-1)+fib(n-2);
}

int fibDP(int n, vector<int>& f){
    if(n==0 || n==1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n]= fibDP(n-1, f)+ fibDP(n-2, f);
    return f[n];
}
int fibTab(int n){
    vector<int> fib(n+1, 0);
    fib[0]=0;
    fib[1]=1;

    for(int i=2; i<=n; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int main(){
    int n=6;
    cout<<fibTab(n)<<endl;
    return 0;
}