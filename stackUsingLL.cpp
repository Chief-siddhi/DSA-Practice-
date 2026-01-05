#include <iostream>
using namespace std;

// create stack using linked list
template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <class T>
class Stack {
    Node<T>* head;

public:
    Stack() {
        head = NULL;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == NULL) return; // optional: handle underflow

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() {
        if (head == NULL) {
            throw runtime_error("Stack is empty");
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}
