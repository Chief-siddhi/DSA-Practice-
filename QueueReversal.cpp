//reverse a queue 
//we will use a stack to reverse the ueue
//we will push the elements in the stack and then pop them from queue
//after that we will push them back into the queue as the stack is last in first out 
//eventually the queue will be reversed 
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> q){
    stack<int> s;
    //push all elements of queue into stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    //pop all elements from stack and push them back into queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    reverseQueue(q);

    //print reversed queue
    while(!q.empty()){
        cout<< q.front()<< " ";
        q.pop();
    }
    cout<< endl;
    return 0;
}