#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* popFront(Node* head){
    if(head == nullptr){
        cout<<"List is empty!"<<endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

void printList(Node* head){
    while (head != nullptr){
        cout << head->data <<" ";
        head = head->next;
    }
    cout<< endl;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout<<"Original List : ";
    printList(head);

    head = popFront(head);
    printList(head);
    return 0;
}