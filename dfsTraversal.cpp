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
    void dfsHelper(int u, vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;
        for(int v: l[u]){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    void dfs(){
        int src=0;
        vector<bool> vis(v,false);
        dfsHelper(src, vis);
        cout<<endl;
    }

};
int main() {
    Graph g(5);   // create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "DFS traversal starting from node 0: ";
    g.dfs();
    return 0;
}