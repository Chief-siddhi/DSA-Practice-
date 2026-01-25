//weakest soldier
//for a M*N matrix, a row is weaker than a row j if one of the following is true
//the number od soldiers in row i is less than the number of soldiers in row j.
//both rows have the same number of soldiers and i<j
//find k weakest rows
//we will use priority queue and will create a minheap
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
public:
    int count;
    int idx; 

    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const{
        if(this->count == obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count; //minheap
    }
};

void weakestSoldier(vector<vector<int>> matrix, int K){
    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++){
        int count =0;
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++){
            count++;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0; i<K; i++){
        cout<<"Row"<<pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<vector<int>> matrix = {{1,0,0,0},
                                 {1,1,1,1},
                                 {1,0,0,0},
                                 {1,0,0,0}};

    weakestSoldier(matrix,2);
    return 0;
}