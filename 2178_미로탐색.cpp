#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[101][101];
int arr[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    visited[x][y] = 1;
    q.push({x, y});

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            // if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            // if(visited[nx][ny] || arr[nx][ny] != 1) continue;

            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(visited[nx][ny] == 0 && arr[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    arr[nx][ny] = arr[cx][cy] + 1;
                }
            }
            
        }
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            //cin >> arr[i][j];
            scanf("%1d", &arr[i][j]);
        }
    }

    arr[0][0] = 1;
    bfs(0, 0);

    cout << arr[n-1][m-1] << "\n";

    return 0;
}