#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    unordered_set<string> destinations;

    // store all destination cities
    for (auto ticket : tickets) {
        destinations.insert(ticket.second);
    }

    // find starting city
    string start = "";
    for (auto ticket : tickets) {
        if (destinations.find(ticket.first) == destinations.end()) {
            start = ticket.first;
            break;
        }
    }

    // print itinerary
    cout << start;
    while (tickets.count(start)) {
        cout << " -> " << tickets[start];
        start = tickets[start];
    }
    cout << endl;
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
    return 0;
}
