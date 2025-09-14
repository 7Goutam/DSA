#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* insertAtTail(Node* head, int val){
    Node* newNode = new Node(val);
    
    if(head == nullptr) {
        return newNode;
    }
    Node* temp = head; 
    while (temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void printList(Node* head){
    while(head !=NULL){
        cout<< head->data <<" ";
        head = head ->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL; 
    head = insertAtTail(head,30);
    head = insertAtTail(head,20);
    head = insertAtTail(head,10);

    printList(head);
    
    return 0;
}