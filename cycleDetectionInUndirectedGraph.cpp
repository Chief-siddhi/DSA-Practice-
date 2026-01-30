#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool UndirCycleHelper(int src, int parent, vector<bool>& vis) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (UndirCycleHelper(v, src, vis))
                    return true;
            }
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycleUndirected() {
        vector<bool> vis(V, false);

        // handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (UndirCycleHelper(i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2); // cycle here
    graph.addEdge(3, 4);

    cout << graph.isCycleUndirected() << endl; // 1 = true

    return 0;
}
