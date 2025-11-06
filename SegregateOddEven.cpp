#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to segregate odd and even positioned nodes
Node* segregateOddEven(Node* head) {
    if (!head || !head->next) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // store starting node of even list

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead; // connect odd list to even list
    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = segregateOddEven(head);

    cout << "After segregation: ";
    printList(head);

    return 0;
}
