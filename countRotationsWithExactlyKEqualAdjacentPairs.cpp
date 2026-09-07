//count rotations with exactly K equal Adjacent pairs 

#include<iostream>
#include<vector>
using namespace std;

int countRotations(string s, int k){
    int n = s.length();
    int answer = 0;
    for(int start=0; start<n; start++){
        int score = 0;

        for(int i=0; i<n-1; i++){
            char first = s[(start+i)%n];
            char second = s[(start+i+1)%n];

            if(first == second){
                score++;
            }
        }
        if(score == k){
            answer++;
        }
    }
    return answer;
}