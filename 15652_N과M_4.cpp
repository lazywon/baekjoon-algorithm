#include <bits/stdc++.h>
using namespace std;

int n, m;
//int visit[10];
vector<int> vc;

void dfs(int cur, int cnt) {
    if(cnt == m) {
        for(int i=0;i<vc.size();i++) {
            cout << vc[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=cur;i<=n;i++) {
        if(vc.size() < m) {
            vc.push_back(i);
            dfs(i, cnt+1);
            vc.pop_back();

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(1, 0);

    return 0;
}