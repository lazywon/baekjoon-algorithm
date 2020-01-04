#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6 - a - b;
    func(a, c, n-1);
    cout << a << ' ' << b << '\n';
    func(c, b, n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    //cout << pow(2, n) - 1 << "\n"; //2의 n승 -> 틀림
    // (1 << n) - 1 도 같은 방식.
    func(1, 3, n);

    return 0;
}