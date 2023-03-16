#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
    stack<int> st;
    string str;
    int iNum;

    while (cin >> str) {
        if (str == "push") {
            cin >> iNum;
            st.push(iNum);
            cout << "ok" << '\n';
        } 
        else if (str == "pop") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else cout << "error" << '\n';
        }
        else if (str == "back") {
            if (!st.empty())  cout << st.top() << '\n';
            else cout << "error" << '\n';
        }
        else if (str == "size") {
            cout << st.size() << '\n';
        }
        else if (str == "clear") {
            while (!st.empty()) {
                st.pop();
            }
            cout << "ok" << '\n';
        }
        if (str == "exit") {
            cout << "bye" << '\n';
            break;
        }
    }
}
