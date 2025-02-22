#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to append a node to the linked list
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove the N-th node from the end of the list
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node();
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Skip the N-th node
    slow->next = slow->next->next;

    return dummy->next; // Return updated head
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, pos;
    cin >> n;

    Node* head = nullptr;

    // Creating the linked list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        append(head, value);
    }

    cin >> pos; // Position of the node to remove

    head = removeNthFromEnd(head, pos);

    printList(head);

    return 0;
}
