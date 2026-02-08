// class Solution {
// public:
//     vector<int> parent, rank;

//     int find(int x){
//         if(parent[x] == x)
//             return x;
//         return parent[x] = find(parent[x]);
//     }

//     bool unionSet(int u, int v){
//         int pu = find(u);
//         int pv = find(v);

//         // cycle found
//         if(pu == pv)
//             return false;

//         if(rank[pu] < rank[pv]){
//             parent[pu] = pv;
//         }
//         else if(rank[pu] > rank[pv]){
//             parent[pv] = pu;
//         }
//         else{
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//         return true;
//     }

//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();

//         parent.resize(n + 1);
//         rank.resize(n + 1, 0);

//         for(int i = 1; i <= n; i++)
//             parent[i] = i;

//         for(auto &e : edges){
//             if(!unionSet(e[0], e[1])){
//                 return e;   // redundant edge
//             }
//         }
//         return {};
//     }
// };
