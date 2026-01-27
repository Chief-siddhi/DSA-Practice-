#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
        freq = 0;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) {
        Node* temp = root;

        for(char ch : key) {
            if(temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
                temp->children[ch]->freq = 1;
            } else {
                temp->children[ch]->freq++;
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    string getPrefix(string key) {
        Node* temp = root;
        string prefix = "";

        for(char ch : key) {
            prefix += ch;
            temp = temp->children[ch];
            if(temp->freq == 1) {
                break;
            }
        }
        return prefix;
    }
};

void prefixProblem(vector<string> dict) {
    Trie trie;

    for(string word : dict) {
        trie.insert(word);
    }

    for(string word : dict) {
        cout << trie.getPrefix(word) << endl;
    }
}

int main() {
    vector<string> dict = {"zebra", "dog", "duck", "dove"};
    prefixProblem(dict);
    return 0;
}
