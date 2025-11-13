#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find middle node
Node* getMiddle(Node* head) {
    if (!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted lists
Node* mergeLists(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    if (left->data <= right->data) {
        result = left;
        result->next = mergeLists(left->next, right);
    } else {
        result = right;
        result->next = mergeLists(left, right->next);
    }
    return result;
}

// Function to perform merge sort on linked list
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    // Find the middle of the list
    Node* mid = getMiddle(head);
    Node* right = mid->next;
    mid->next = NULL;

    // Sort the two halves
    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);

    // Merge sorted halves
    return mergeLists(leftSorted, rightSorted);
}

// Utility to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
