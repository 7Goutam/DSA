#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int>& st, int x) {
    // Base case: if stack is empty
    if (st.empty()) {
        st.push(x);
        return;
    }

    // Step 1: Remove the top element
    int topElement = st.top();
    st.pop();

    // Step 2: Recursively call for the remaining stack
    pushAtBottom(st, x);

    // Step 3: Push back the top element
    st.push(topElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int x = 99;
    pushAtBottom(st, x);

    cout << "Stack after pushing " << x << " at bottom:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
