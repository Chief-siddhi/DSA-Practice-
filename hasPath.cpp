#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
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

    //by DFS 
    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int> neighbors=l[src];

        for(int v:neighbors){
            if(!vis[v]){
                if(pathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

