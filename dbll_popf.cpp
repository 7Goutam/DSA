#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
    void insertFront(Node*& head, int val){
        Node* newNode=new Node(val);

        newNode->next = head;
        if(head!=NULL){
            (head)->prev=newNode;
        }
        head=newNode;
    }

    void deleteFront(Node*& head) {
    if (head == NULL) return; // empty list
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}


 void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    insertFront(head,5);
    insertFront(head,10);
    insertFront(head,15);
    insertFront(head,20);
    insertFront(head,25);

    
    printList(head);

    deleteFront(head);

      printList(head);
    return 0;
}