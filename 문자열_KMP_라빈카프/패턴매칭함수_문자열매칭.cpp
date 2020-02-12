#include <bits/stdc++.h>
using namespace std;

bool find(string &A, string& B) {
    if(A.size() < B.size()) return false;

    for(int st=0;st<=A.size()-B.size();st++) {
        bool isMatch = true;

        for(int i=st;i<st+B.size();i++) {
            if(A[i] != B[i-st]) {
                isMatch = false;
                break;
            }
        }
        if(isMatch) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    vector<string> a;
    vector<string> b;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<m;i++) {
        string tmp2;
        cin >> tmp2;
        b.push_back(tmp2);
    }


    return 0;
}