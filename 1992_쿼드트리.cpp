#include <bits/stdc++.h>
using namespace std;

int mapp[65][65];

void solve(int x, int y, int n) {
    if(n == 1) {
        cout << mapp[x][y];
        return;
    }

    bool zero = true, one = true;
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            if(mapp[i][j] == 1) {
                zero = false;
            } else {
                one = false;
            }
        }
    }

    if(zero) cout << 0;
    else if(one) cout << 1;
    else {
        cout << "(";
        solve(x, y, n / 2); // 2사분면
        solve(x, y + n / 2, n / 2); // 1사분면
        solve(x + n / 2, y, n / 2); // 3사분면
        solve(x + n / 2, y + n / 2, n / 2); // 4사분면
        cout << ")";
    }
    return;
    
}

int main() { 
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%1d", &mapp[i][j]);
        }
    }
    solve(0, 0, n);
    cout << "\n";

    return 0;
}