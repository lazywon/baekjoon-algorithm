#include <bits/stdc++.h>
using namespace std;

int n;
bool issued1[30]; // column을 차지하고 있는지
bool issued2[30]; // / 방향 대각선을 차지하고 있는지
bool issued3[30]; // \ 방향 대각선을 차지하고 있는지
int cnt = 0;

void func(int cur) {
    if(cur == n) {
        cnt++;
        return;
    }

    for(int i=0;i<n;i++) { // (cur, i)에 퀸을 놓을 예정
        if(issued1[i] || issued2[i + cur] || issued3[cur - i + n - 1]) continue;

        issued1[i] = 1;  // y
        issued2[i + cur] = 1;  // x+y
        issued3[cur - i + n - 1] = 1;  // x-y+n-1
        func(cur + 1);
        issued1[i] = 0;
        issued2[i + cur] = 0;
        issued3[cur - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt << "\n";

    return 0;
}