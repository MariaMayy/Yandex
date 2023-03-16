#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> st;
    string bracket;
    
    cin >> bracket;
    
    for (int i = 0; i < bracket.length(); i++) {
        switch (bracket[i]) {
            case '(':
                st.push(bracket[i]);
                break;
            case '{':
                st.push(bracket[i]);
                break;
            case '[':
                st.push(bracket[i]);
                break;
            case ')': 
                if (!st.empty() && st.top() == '(') st.pop();
                break;
            case '}': 
                if (!st.empty() && st.top() == '{') st.pop();
                break;
            case ']': 
                if (!st.empty() && st.top() == '[') st.pop();
                break;
        }
    }
    
    if (st.empty()) cout << "yes";
    else cout << "no";
    return 0;
}