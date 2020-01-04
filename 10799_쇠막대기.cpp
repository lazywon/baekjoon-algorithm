#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;

    int result = 0;
    
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else {
            st.pop();
            //레이저의 경우
            if(s[i-1] == '(') {
                result += st.size();
            } else { //막대기의 끝 부분의 경우
                result += 1;
            }
        }
    }

    cout << result << "\n";

    return 0;
}