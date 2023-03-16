#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> que1;
    queue<int> que2;
    int iCount = 0;

    for (int i = 0; i < 5; i++) {
        int iNum;
        cin >> iNum;
        que1.push(iNum);
    }

    for (int i = 0; i < 5; i++) {
        int iNum;
        cin >> iNum;
        que2.push(iNum);
    }

    while (!que1.empty() && !que2.empty() && iCount <= 1000000) {
        if ((que1.front() == 0 && que2.front() == 9) || (que1.front() > que2.front() && !(que1.front() == 9 && que2.front() == 0))) {
            que1.push(que1.front());
            que1.pop();
            que1.push(que2.front());
            que2.pop();
        } 
        else {
            que2.push(que1.front());
            que1.pop();
            que2.push(que2.front());
            que2.pop();
        }
        iCount++;
    }

    if (que1.empty()) cout << "second " << iCount;
    else if (que2.empty()) cout << "first " << iCount;
    else cout << "botva";

    return 0;
}

 