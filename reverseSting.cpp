#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reverseString(string &str) {
    stack<char> st;

    // Step 1: Push all characters of the string onto the stack
    for (char ch : str) {
        st.push(ch);
    }

    // Step 2: Pop characters from the stack and form the reversed string
    str = "";
    while (!st.empty()) {
        str += st.top();
        st.pop();
    }
}
int main() {
    string str = "Hello, World!";
    cout << "Original String: " << str << endl;

    reverseString(str);

    cout << "Reversed String: " << str << endl;
    return 0;
}