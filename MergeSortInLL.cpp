//merge sort in linked list 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// --- merge two sorted lists ---
Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

// --- find middle using slow/fast pointers ---
Node* findMiddle(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    // fast moves 2, slow moves 1
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// --- merge sort on linked list ---
Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head; // base case: 0 or 1 element

    Node* mid = findMiddle(head);

    Node* right = mid->next;
    mid->next = nullptr; // split into two lists
    Node* left = head;

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeLists(left, right);
}

// utility: push at head
void push(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// utility: print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // example list
    push(head, 3);
    push(head, 1);
    push(head, 5);
    push(head, 2);
    push(head, 4);

    cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}