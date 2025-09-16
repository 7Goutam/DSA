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

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while (fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            cout<<"Cycle exists"<<endl;
            isCycle = true;
            break;
        } 
    }
     if(!isCycle){
        cout<< "Cycle doesn't exists "<<endl;
        return;
     }
     slow =head;
     if(slow==fast){
        while(fast->next != slow){
            fast = fast ->next;
        }
        fast->next=NULL;
     }
      Node* prev = fast;
     while (slow!=fast){
        slow = slow->next;
        prev = fast;
        fast = fast->next;
     }
     prev->next= NULL;
}

void printList(Node* head){
    while (head != NULL){
        cout <<head->data<<"->";
        head = head->next;
    }
    cout << endl;   
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    removeCycle(head);

    printList(head);
    return 0;
}