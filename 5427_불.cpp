#include <bits/stdc++.h>
using namespace std;

int w, h;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[1001][1001];
char arr[1001][1001];
int ans_arr[1001][1001];
//string arr[1001];
vector<pair<int, int> > fire;

void init() {
    fire.clear();
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            visited[i][j] = 0;
        }
    }
}

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    queue<pair<int, int> > fq;
    q.push(make_pair(x, y));
    for(int f=0;f<fire.size();f++) {
        fq.push(fire[f]);
    }
    int result = 0;

    visited[x][y] = 1;
    //ans_arr[x][y] = 1;
    //int cnt = 0;

    while(!q.empty()) {
        //불 움직임
        int fqSize = fq.size();
        for(int i=0;i<fqSize;i++) {
            int fcx = fq.front().first;
            int fcy = fq.front().second;
            fq.pop();

            for(int dir=0;dir<4;dir++) {
                int fnx = fcx + dx[dir];
                int fny = fcy + dy[dir];
                if(fnx >= 0 && fnx < h && fny >= 0 && fny < w) {
                    if(arr[fnx][fny] == '.') {
                        arr[fnx][fny] = '*';
                        fq.push(make_pair(fnx, fny));
                    }
                }
            }
        }
        // for(int i=0;i<h;i++) {
        //     for(int j=0;j<w;j++) {
        //         cout << arr[i][j];
        //     }
        //     cout << "\n";
        // }


        //사람 움직임
        int qSize = q.size();
        //cout << qSize << "\n";
        for(int i=0;i<qSize;i++) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if(cx == 0 || cx == h-1 || cy == 0 || cy == w-1) {
                //cnt++;
                return result + 1;
            }
            
            for(int dir=0;dir<4;dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(visited[nx][ny] == 1 || arr[nx][ny] == '#' || arr[nx][ny] == '*') continue;
            
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                //ans_arr[nx][ny] = ans_arr[cx][cy] + 1;
                //cnt++;
            }
        }
        result++;
    }

    // for(int i=0;i<h;i++) {
    //     for(int j=0;j<w;j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }

    return -1;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        init();
        cin >> w >> h;

        int x, y;
        for(int i=0;i<h;i++) {
            //cin >> arr[i];
            for(int j=0;j<w;j++) {
                cin >> arr[i][j];
                
                if(arr[i][j] == '@') {
                    x = i;
                    y = j;
                } else if(arr[i][j] == '*') {
                    fire.push_back(make_pair(i, j));
                }
            }
        }

        int ret = bfs(x, y);

        if(ret == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ret << "\n";
        }


    }


    return 0;
}