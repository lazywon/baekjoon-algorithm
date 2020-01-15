#include <bits/stdc++.h>
using namespace std;

int n;
//vector<pair<int, int> > v; vector 쓰면 에러..
pair<int, int> s[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s[i].second >> s[i].first;
    }

    sort(s, s+n);

    int count = 0;
    int cur = 0;

    // for(int i=0;i<n;i++) {
    //     if(cur > s[i].second) continue;
    //     count++;
    //     cur = s[i].first;
    // }

    for(int i=0;i<n;i++) {
        if(cur <= s[i].second)  {
            count++;
            cur = s[i].first;
        }
        else continue;
    }

    cout << count << "\n";

    return 0;
}