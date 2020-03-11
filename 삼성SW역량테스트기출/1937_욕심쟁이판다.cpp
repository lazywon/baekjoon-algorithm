#include <bits/stdc++.h>
using namespace std;

#define MAX 500 + 1

int n, result;
int Map[MAX][MAX];
int dp[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) { //최장 경로 탐색
    if(dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if(Map[x][y] < Map[nx][ny]) {
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> Map[i][j];

        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            result = max(result, dfs(i, j));            
        }
    }

    cout << result << "\n";

    return 0;
}