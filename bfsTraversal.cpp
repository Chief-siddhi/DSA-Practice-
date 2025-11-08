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

    void bfs(int start) {
        vector<bool> vis(v, false);
        queue<int> Q;

        Q.push(start);
        vis[start] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for (int nbr : l[u]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    Q.push(nbr);
                }
            }
        }
    }
};

int main() {
    Graph g(5);   // create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS traversal starting from node 0: ";
    g.bfs(0);
    return 0;
}
