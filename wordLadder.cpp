//word ladder - leetcode 127
//hard level problem 
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int wordLadder(string startWord, string targetWord, vector<string>& wordList){
    queue<pair<string,int>> q;
    q.push({startWord,1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==targetWord) return steps;

        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch<='z'; ch++){
                word[i]=ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;

}
//N * word.length * 26 * log N where N is the number of words in the wordList. We are iterating through each word in the wordList, and for each word, we are iterating through its characters and trying all possible character replacements (26 lowercase letters). The log N factor comes from the unordered_set operations (insertion and lookup).
//Space complexity: O(N) for the queue and the unordered_set, where N is the number of words in the wordList. In the worst case, all words could be added to the queue and the unordered_set.