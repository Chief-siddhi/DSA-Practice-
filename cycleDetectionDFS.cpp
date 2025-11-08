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
    bool isCycleUndirDFS(int src, int par, vector<bool>& vis) {
        vis[src] = true;

        list<int> neighbors = l[src];
        for(int v:neighbors=l[src]){
            if(!vis[v]){
                if(isCycleUndirDFS(v,src,vis)){
                    return true;
                }
            }else if(v!=par){
                return true;
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

    vector<bool> vis(5, false);
    if(g.isCycleUndirDFS(0, -1, vis)){
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}