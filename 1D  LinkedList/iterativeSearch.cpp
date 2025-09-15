#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

bool search(Node* head, int key){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key)
            return true; 
        temp = temp->next;
    }
    return false;
}
int main(){
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
head->next->next->next = new Node(40);

int key = 70;
if(search(head, key)){
    cout << "Found" << endl;
}
    else{
    cout<<"Not Found" << endl;
    }
cout<<search(head, key);
    return 0;
}