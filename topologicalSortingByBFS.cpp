#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int V;                     // number of vertices
vector<list<int>> l;       // adjacency list

void calcInDegree(vector<int> &indeg) {
    for (int u = 0; u < V; u++) {
        for (int v : l[u]) {
            indeg[v]++;
        }
    }
}

void topoSort2() {          // Kahn's algorithm
    vector<int> indeg(V, 0);
    calcInDegree(indeg);

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int v : l[curr]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    V = 6;                     // number of vertices
    l.resize(V);

    // adding edges
    l[5].push_back(2);
    l[5].push_back(0);
    l[4].push_back(0);
    l[4].push_back(1);
    l[2].push_back(3);
    l[3].push_back(1);

    cout << "Topological Sort: ";
    topoSort2();

    return 0;
}
