#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    string s;
    stack<int> st;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        if(s == "push") {
            cin >> x;
            st.push(x);
        } else if(s == "pop") {
            if(st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if(s == "size") {
            cout << st.size() << "\n";
        } else if(s == "empty") {
            if(st.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if(s == "top") {
            if(st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
            }
        }
    }


    return 0;
}