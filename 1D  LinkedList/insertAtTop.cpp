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

Node* insertAtHead(Node* head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
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
    head = insertAtHead(head,30);
    head = insertAtHead(head,20);
    head = insertAtHead(head,10);

    printList(head);
    
    return 0;
}