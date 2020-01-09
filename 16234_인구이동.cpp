#include<bits/stdc++.h>
using namespace std;

int n, L, R;
int cnt, people;
int arr[51][51];
bool visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int> > pos; 

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    pos.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;
            int diff = abs(arr[cx][cy] - arr[nx][ny]);
            if(diff >= L && diff <= R) { //인구이동
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                pos.push(make_pair(nx, ny));
                cnt++;
                people += arr[nx][ny];
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L >> R;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    int ret = 0;

    while(1) { //인구이동이 없을때 까지
        memset(visited, 0, sizeof(visited));

        bool check = false;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(visited[i][j]) continue;
                visited[i][j] = true;
                people = arr[i][j];
                cnt = 1;

                bfs(i, j);

                int average = people / pos.size();
                
                if(cnt >= 2) check = true; //국경이 하나라도 열리면

                //visited 체크
                while(!pos.empty()) {
                    arr[pos.front().first][pos.front().second] = average;
                    pos.pop();
                    
                }

            }
        }
        if(check == true) ret++;
        else break;
    }

    cout << ret << "\n";

    return 0;
}
//rhasya