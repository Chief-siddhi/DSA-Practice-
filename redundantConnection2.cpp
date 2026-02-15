#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int find(vector<int>& dsu, int x) {
        if (dsu[x] != x)
            dsu[x] = find(dsu, dsu[x]);
        return dsu[x];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1, 0);
        vector<int> cand1;
        vector<int> cand2;

        // Step 1: detect node with two parents
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                cand1.push_back(parent[v]);
                cand1.push_back(v);

                cand2.push_back(u);
                cand2.push_back(v);

                // invalidate second edge temporarily
                edges[i][1] = 0;
            }
        }

        // DSU init
        vector<int> dsu(n + 1);
        for (int i = 1; i <= n; i++)
            dsu[i] = i;

        // Step 2: cycle check
        for (int i = 0; i < n; i++) {
            if (edges[i][1] == 0) continue;

            int u = edges[i][0];
            int v = edges[i][1];

            int pu = find(dsu, u);

            if (pu == v) {
                if (cand1.empty())
                    return edges[i];
                else
                    return cand1;
            }

            dsu[v] = pu;
        }

        return cand2;
    }