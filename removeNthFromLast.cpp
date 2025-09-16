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
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    int pos = length - n+ 1;
    if(pos==1){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    temp = head;
    for(int i=1; i<pos-1;i++){
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next =temp->next->next;
    delete delNode;

    return head;
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