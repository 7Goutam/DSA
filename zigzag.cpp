#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* zigZagList(Node* head) {
    if (!head || !head->next) return head;

    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split into two halves
    Node* second = slow->next;
    slow->next = NULL;

    //  Reverse second half
    second = reverseList(second);

    //  Merge alternately
    Node* first = head;
    Node* temp1;
    Node* temp2;
    while (first && second) {
        temp1 = first->next;
        temp2 = second->next;

        first->next = second;
        if (temp1 == NULL) break;

        second->next = temp1;

        first = temp1;
        second = temp2;
    }

    return head;
}

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
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    head = zigZagList(head);

    cout << "ZigZag List:   ";
    printList(head);

    return 0;
}




