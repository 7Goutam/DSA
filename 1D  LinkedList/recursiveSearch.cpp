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

    int searchRecursive(Node* head, int key, int index = 0){
        if(head== NULL) return -1;
        if(head->data == key){
            return index;
        }

        return searchRecursive(head->next, key, index + 1);
    }
int main(){
   Node* head = new Node(10);
   head->next = new Node(20);
   head->next->next = new Node(30);
   head->next->next->next = new Node(40);
    int key = 40;
    int pos = searchRecursive(head, key);
    if(pos != -1){
        cout<<"Found at index "<< pos << endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}