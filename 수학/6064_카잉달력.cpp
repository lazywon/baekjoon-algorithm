#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, int x, int y) {
    if(x == m) x = 0;
    if(y == n) y = 0;

    for(int i=x;i<=m*n;i+=m) {
        if(i%m == x && i%n == y) return i;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int T=0;T<t;T++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        cout << solve(m, n, x, y) << "\n"; 

    }

    return 0;
}