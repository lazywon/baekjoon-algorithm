#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int dp[n];

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
        //끝나고 나누면 int overflow 발생
    }

    cout << dp[n] << "\n";

    return 0;
}