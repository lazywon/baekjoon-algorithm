//일치하는 문자열 찾기
// O(문자열크기 + 찾을 문자열 크기) 만큼의 시간복잡도

#include <bits/stdc++.h>
using namespace std;

vector<int> getPi(string p) {
    int m = (int)p.size(); //찾을 문자열 길이
    int j = 0;
    vector<int> pi(m, 0);

    for(int i=1;i<m;i++) {
        while(j > 0 && p[i] != p[j]) { //불일치한다면
            j = pi[j - 1]; // 중간단계 넘어가기
        }
        if(p[i] == p[j]) {
            pi[i] = ++j; //일치하는 길이 누적증가
        }
    }
    return pi;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size();
    int m = (int)p.size();
    int j = 0;

    for(int i=0;i<n;i++) {
        while(j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }

        if(s[i] == p[j]) {
            if(j == m-1) {
                ans.push_back(i - m + 1); 
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    getline(cin, s);
    getline(cin, p);
    
    auto matched = kmp(s, p);

    cout << (int)matched.size() << "\n";

    for(auto i : matched)
        cout << i + 1 << " ";

    return 0;
}