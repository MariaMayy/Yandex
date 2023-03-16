#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;


int main() {
    string str;
    stack<int> st;

    getline(cin,  str);

    for (char c : str) {
        if (isdigit(c)) st.push(c - '0');
        else if (c != ' ') {
            int iUp = st.top();
            st.pop();
            int iDown = st.top();
            st.pop();
            
            switch (c) {
            case '+': 
                st.push(iDown + iUp);
                break;
            case '-': 
                st.push(iDown - iUp);
                break;
            case '*':
                st.push(iDown * iUp);
                break;
            
            }
        }
    }

    cout << st.top();

    return 0;
}
