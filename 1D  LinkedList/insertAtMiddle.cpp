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
Node* insertAtPosition(Node* head, int val, int pos){
    Node* newNode = new Node(val);
    if(pos==1){
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    for(int i = 1; i<pos-1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Invalid position! "<<endl;
        return head;
    }
    newNode->next =temp->next;
    temp->next = newNode ;
}

void printList(Node* head){
    while(head !=nullptr){
        cout<< head->data <<" ";
        head = head ->next;
    }
    cout<<endl;
}

int main(){
    Node* head = nullptr;

    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);
    head = insertAtPosition(head, 40, 4);

    printList(head);

    return 0;
}