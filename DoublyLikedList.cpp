#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        prev = next=NULL;
    }
};
class DoublyList{
public:
    Node* head;
    Node* tail;
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            newNode->next = head;
        }
    }

    void printList(){
        Node* temp = haed;
        while(temp!=NULL){
            cout<< temp->data;
        }
        cout<<"NULL\n";
    }
};

int main(){
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    
    return 0;
}