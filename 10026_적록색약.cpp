#include <bits/stdc++.h>
using namespace std;

int n;
int visited[101][101];
char arr[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void bfs(int x, int y, char color) {
    queue<pair<int, int> > q;
    visited[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] || arr[nx][ny] != color) continue;
            visited[nx][ny] = 1; 
            q.push(make_pair(nx, ny));
                      
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] || arr[i][j] != 'R') continue;
            count++;
            bfs(i, j, 'R');
        }
    }
    //cout << count << "\n";
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] || arr[i][j] != 'G') continue;
            count++;
            bfs(i, j, 'G');
        }
    }
    //cout << count << "\n";
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] || arr[i][j] != 'B') continue;
            count++;
            bfs(i, j, 'B');
        }
    }
    memset(visited, 0, sizeof(visited));

    //적록색약의 경우
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j] == 'G') {
                arr[i][j] = 'R';
            }
        }
    }

    int count2 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] || arr[i][j] != 'R') continue;
            count2++;
            bfs(i, j, 'R');
        }
    }
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j] || arr[i][j] != 'B') continue;
            count2++;
            bfs(i, j, 'B');
        }
    }
    memset(visited, 0, sizeof(visited));

    cout << count << " " << count2 << "\n";

    return 0;
}