#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        if (mp.find(node) != mp.end())
            return mp[node];

        Node* clone = new Node(node->val);

        mp[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

int main() {
    // Example graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution s;

    Node* clonedGraph = s.cloneGraph(n1);

    cout << "Original node: " << n1->val << endl;
    cout << "Cloned node: " << clonedGraph->val << endl;

    return 0;
}