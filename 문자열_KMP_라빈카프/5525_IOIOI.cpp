/*
    하나의 문자열 안에 패턴 문자열이 몇개 들어있는지 구하는 문제
    직관적으로 풀면 TLE 발생, 시간복잡도를 O(N)으로 줄여야함.
    핵심은 O의 개수를 통해 Pn인지 파악하는 것
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, len;
    string s;
    cin >> n >> len >> s;

    int result = 0;

    for(int i=0;i<s.length();i++) {
        if(s[i+1] == 'O' && s[i+2] == 'I') {
            //O의 개수가 중요
            int o = 0;
            while(s[i] == 'I' && s[i+1] == 'O') {
                i += 2;
                o++;
                if(s[i] == 'I' && o == n) {
                    o--; //이전 o는 확인 안해도 됨
                    result++;
                }
            }
        }
    }
    
    cout << result << "\n";

    return 0;
}