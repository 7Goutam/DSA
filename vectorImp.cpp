#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Stack{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
    }
    void pop(){
        if(!vec.empty()){
            vec.pop_back();
        }
    }
    int top(){
       int lastIdx = vec.size() - 1;
       return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.empty();
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}