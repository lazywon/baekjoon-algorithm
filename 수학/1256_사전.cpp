//dp

#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[202][102] = {0, };
long long k;
const int MAX = 1000000001;

void init() {
    for(int i=0;i<=n+m;i++) {
        dp[i][0] = 1;
        for(int j=1;j<i;j++) {
            //nCm = n-1Cm + n-1Cm-1
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if(dp[i][j] > MAX) dp[i][j] = MAX;
        }
        dp[i][i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    init();
    int cnt, size;

    cnt = 0;
    size = n + m;

    if(dp[n + m][m] < k) {
        cout << -1 << endl;
    }
    else {
        while(cnt < size) { // 이 부분 이해 nono...
            if(k <= dp[n + m - 1][m]) {
                cout << "a";
                n--;
            } else {
                k -= dp[n + m - 1][m];
                cout << "z";
                m--;
            }
            cnt++;
        }
    }

    return 0;
}