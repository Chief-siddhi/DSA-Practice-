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
        l[v].push_back(u); // undirected graph
    }

    bool isBipartite() {
        vector<bool> vis(v, false);
        vector<int> color(v, -1);
        queue<int> q;

        // Handle disconnected graph
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
                color[i] = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int nbr : l[curr]) {
                        if (!vis[nbr]) {
                            vis[nbr] = true;
                            color[nbr] = 1 - color[curr];
                            q.push(nbr);
                        } else if (color[nbr] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
