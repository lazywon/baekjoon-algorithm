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
            //�������� ���
            if(s[i-1] == '(') {
                result += st.size();
            } else { //������� �� �κ��� ���
                result += 1;
            }
        }
    }

    cout << result << "\n";

    return 0;
}