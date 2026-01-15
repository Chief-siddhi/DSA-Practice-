#include<iostream>
using namespace std;

class Queue{
    int* arr;

    int capacity;
    int currSize;

    int f,r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int(capacity);
        currSize = 0;
        f = 0;
        r=-1;
    }
    void push(int data){
        if(currSize == capacity){
            cout<< "Queue is full"<<endl;
            return;
        }
        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f = (f+1)% capacity;
        currSize--;
    } 
    int front(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];

    }
    bool empty(){
       return currSize == 0;
    }
};

int main(){
    Queue q(4);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); // Queue is full

    cout<< q.front()<<endl; // 10
    q.pop();
    
    return 0;
}