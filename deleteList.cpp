#include<iostream>
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

void insertAtTAil(Node* &head, int val) {
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

void deleteList(Node* &head){
    if(head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}

int main(){
    Node* head = NULL;
    insertAtTAil(head, 1);
    insertAtTAil(head, 2);
    insertAtTAil(head, 3);
    insertAtTAil(head, 4);

    deleteList(head);

    if(head == NULL) {
        cout << "List deleted successfully." << endl;
    } else {
        cout << "List deletion failed." << endl;
    }

    return 0;
}