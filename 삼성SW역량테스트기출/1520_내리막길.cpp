#include <bits/stdc++.h>
using namespace std;
#define MAX 500 + 1

int n, m, ans;
int Map[MAX][MAX];
int dp[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

//dp[x][y] = (x, y) 지점일 때 존재하는 경로의 개수

int dfs(int x, int y) {
    //m-1, n-1 부터 0, 0까지 차례로 내려가는 경우

    if(x == 0 && y == 0) {
        return 1;
    }

    if(dp[x][y] == -1) {// 방문하지 않은 경로인 경우
        dp[x][y] = 0;
        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if(Map[x][y] < Map[nx][ny]) {
                    dp[x][y] += dfs(nx, ny);
                }
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    memset(dp, -1, sizeof(dp));

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> Map[i][j];
        }
    }

    ans = dfs(m-1, n-1);
    cout << ans << "\n";

    return 0;
}