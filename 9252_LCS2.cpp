#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[1001][1001];
vector<char> ret;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a;
    cin >> b;

    int Max = 0;
    int size = a.size();
    for(int i=1;i<=size;i++) {
        for(int j=1;j<=size;j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(Max < dp[i][j]) {
                    Max = dp[i][j];
                    ret.push_back(a[i-1]);
                }
                
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[size][size] << "\n";

    for(int i=0;i<ret.size();i++) {
        cout << ret[i];
    }
    cout << "\n";

    return 0;
}