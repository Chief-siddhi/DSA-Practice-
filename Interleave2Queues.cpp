#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &org) {
    int n = org.size();
    queue<int> first;

    // Push first half into another queue
    for (int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Interleave the two halves
    while (!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> org;

    // Push elements (even count)
    for (int i = 0; i < 10; i++) {
        org.push(i);
    }

    interLeave(org);

    // Print result
    while (!org.empty()) {
        cout << org.front() << " ";
        org.pop();
    }

    cout << endl;
    return 0;
}
