#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int HashFunction(string key) {
        int idx = 0;
        for (char ch : key) {
            idx = (idx + ch) % totSize;
        }
        return idx;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        currSize = 0;

        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = HashFunction(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize / (double)totSize;
        if (lambda > 1.0) {
            rehash();
        }
    }

    bool exists(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];

        while (temp != NULL) {
            if (temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];

        while (temp != NULL) {
            if (temp->key == key) return temp->val;
            temp = temp->next;
        }
        return -1;
    }
};

int main() {
    HashTable ht;
    ht.insert("India", 150);
    ht.insert("Nepal", 50);
    ht.insert("China", 350);
    ht.insert("US", 250);

    if (ht.exists("India")) {
        cout << "India population: " << ht.search("India") << endl;
    }

    return 0;
}
