#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<int> que;
    string str;
    int iNum;

    while (cin >> str) {
        if (str == "push") {
            cin >> iNum;
            que.push(iNum);
            cout << "ok" << '\n';
        }
        else if (str == "pop") {
            if (!que.empty()) {
                cout << que.front() << '\n';
                que.pop();
            }
            else cout << "error" << '\n';
        }
        else if (str == "front") {
            if (!que.empty()) {
                cout << que.front() << '\n';
            }
            else cout << "error" << '\n';
        }
        else if (str == "size") cout << que.size() << '\n';
        else if (str == "clear") {
            while (!que.empty()) {
                que.pop();
            }
            cout << "ok" << '\n';
        }
        if (str == "exit") {
            cout << "bye" << '\n';
            break;
        }
    }

    return 0;
}