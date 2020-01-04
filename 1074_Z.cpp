#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void func(int x, int y, int n) {
    if(x == r && y == c) {
        cout << ans << "\n";
        return;
    }

    if(r < x + n && r >= x && c < y + n && c >= y) {
        func(x, y, n / 2);
        func(x, y + n / 2, n / 2);
        func(x + n / 2, y, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
    }
    else {
        ans += n * n;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;

    //func(1, 3, n);
    func(0, 0, (1 << n));
    //1 << n --> 2ÀÇ n½Â

    return 0;
}