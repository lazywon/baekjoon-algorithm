#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    stack<int> st;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    vector<char> ret;

    int j = 0;
    int tmp = v[j];
    vector<int>::iterator it;
    it = v.begin();
    for(int i=1;i<=n;i++) {
        st.push(i);
        ret.push_back('+');
        while(!st.empty()) {
            if(*it != st.top()) {
                break;
            } else {
                st.pop();
                ret.push_back('-');
                //tmp = v[j++];
                ++it;
            }
        }
        
    }
    if(st.empty()) {
        for(int i=0;i<ret.size();i++) {
            cout << ret[i] << "\n";
        }
    } else {
        cout << "NO\n";
    }


    return 0;
}