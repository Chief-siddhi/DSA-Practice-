#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> &graph, int V) {

    // Min heap (distance , vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(Edge e : graph[u]) {
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i=0;i<V;i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {

    int V = 6;
    vector<vector<Edge>> graph(V);

    // Edges
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(5,5));

    dijkstra(0, graph, V);

    return 0;
}
