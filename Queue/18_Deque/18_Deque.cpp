#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> deq;
    string str;
    int iNum;

    while (cin >> str) {
        if (str == "push_front") {
            cin >> iNum;
            deq.push_front(iNum);
            cout << "ok" << '\n';
        }
        else if (str == "push_back") {
            cin >> iNum;
            deq.push_back(iNum);
            cout << "ok" << '\n';
        }
        else if (str == "pop_front") {
            if (!deq.empty()) {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
            else cout << "error" << endl;
        }
        else if (str == "pop_back") {
            if (!deq.empty()) {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
            else cout << "error" << endl;
        }
        else if (str == "front") {
            if (!deq.empty()) {
                cout << deq.front() << '\n';
            }
            else cout << "error" << endl;
        }
        else if (str == "back") {
            if (!deq.empty()) {
                cout << deq.back() << '\n';
            }
            else cout << "error" << endl;
        }
        else if (str == "size") cout << deq.size() << endl;
        else if (str == "clear") {
            while (!deq.empty()) {
                deq.pop_back();
            }
            cout << "ok" << endl;
        }
        if (str == "exit") {
            cout << "bye";
            break;
        }
    }

    return 0;
}