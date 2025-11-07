#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* removeNthFromEnd(Node* head, int n){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
    for(int i=0; i<=n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;  
    delete delNode;

    return dummy->next;
}

void printList(Node* head){
    while (head != NULL){
        cout <<head->data<<" ";
        head = head->next;
    }
    cout << endl;   
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout<<"Original List: ";
    printList(head);

    head = removeNthFromEnd(head, 2);

    cout << "After removing 2nd from end: ";
    printList(head);
    return 0;
}