#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int mx = 0;

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = 1;

    int area = 0;

    while(!q.empty()) {
        area++;
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(visited[nx][ny] || arr[nx][ny] == 0) {
                continue;
            }
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    if(area > mx) {
        mx = area;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0 || visited[i][j]) {
                continue;
            }
            bfs(i, j);
            count++;
        }
    }

    cout << count << "\n" << mx << "\n";

    return 0;
}