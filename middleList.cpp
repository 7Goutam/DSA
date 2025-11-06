#include<iostream>
#include<list>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

Node* middleNode(Node* head) {
    if(head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);


    cout << "Linked List: ";
    printList(head);

    Node* mid = middleNode(head);
    if(mid != NULL) {
        cout << "Middle Node: " << mid->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}