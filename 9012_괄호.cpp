#include <bits/stdc++.h>
using namespace std;

void check(string s) {
    stack<char> st;

    int len = (int)s.length();

    for(int j=0;j<len;j++) {
        char c = s[j];

        if(c == '(') {
            st.push(s[j]);
        } else {
            if(!st.empty()) {
                st.pop();
            } else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if(!st.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;

        check(s);
    }

    return 0;
}