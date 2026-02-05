#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<list>

using namespace std;

class Graph {
public:
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

    Graph(int V, bool unDir=true){
        this->V = V;
        l = new list<pair<int,int>>[V];
        this->isUndir = unDir;
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back({v, wt});
        if(isUndir){
            l[v].push_back({u, wt});
        }
    }

    void primsAlgo(int src){
        // Min Heap {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool> mst(V, false);

        pq.push({0, src});
        int ans = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int u = top.second;
            int wt = top.first;

            if(mst[u]) continue;

            mst[u] = true;
            ans += wt;

            // Traverse neighbors
            for(auto nbr : l[u]){
                int v = nbr.first;
                int currWt = nbr.second;

                if(!mst[v]){
                    pq.push({currWt, v});
                }
            }
        }

        cout << "Final cost of MST: " << ans << endl;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.primsAlgo(0);

    return 0;
}
