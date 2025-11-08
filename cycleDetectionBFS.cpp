#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int v;                // number of vertices
    list<int>* l;         // adjacency list

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // for undirected graph
    }

    // BFS-based cycle detection in an undirected graph
    bool isCycleUndirBFS(int src, vector<bool>& vis) {
        queue<pair<int, int>> q; // {node, parent}
        q.push({src, -1});
        vis[src] = true;

        while (!q.empty()) {
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, u});
                } 
                // If visited and not parent → cycle exists
                else if (v != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle() {
        vector<bool> vis(v, false);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (isCycleUndirBFS(i, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);   // create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4); // adding an edge to create a cycle

    if (g.isCycle()) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}
