#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;

    for(int i=1;i<=n;i++) {
        q.push(i);
    }

    cout << "<";

    while(q.size()) {
        if(q.size() == 1) {
            cout << q.front() << ">";
            q.pop();
            break;
        }

        for(int i=1;i<k;i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << "\n";


    return 0;
}
//cloud
//data redundancy
//db,객체지향, 네트워크