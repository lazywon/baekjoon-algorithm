#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 + 1

int tc, w, h;
char Map[MAX][MAX];
int visit[MAX][MAX];
vector<pair<int, int> > fire;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    queue<pair<int, int> > fq; //불

    q.push(make_pair(x, y));
    for(int f=0;f<fire.size();f++) {
        fq.push(fire[f]);
    }

    int result = 0;

    visit[x][y] = 1;

    while(!q.empty()) { //사람이 움직일 위치가 없으면 더이상의 진행이 무의미
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
                    if(Map[fnx][fny] == '.') { //사람이 지워지지 않도록!!
                        Map[fnx][fny] = '*';
                        fq.push(make_pair(fnx, fny));
                    }
                }
            }
        }

        //사람 움직임
        int qSzie = q.size();
        for(int i=0;i<qSzie;i++) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if(cx == 0 || cx == h-1 || cy == 0 || cy == w-1)
                return result + 1;

            for(int dir=0;dir<4;dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if(visit[nx][ny] == 0 && Map[nx][ny] == '.') {
                        visit[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    int x, y;
    for(int T=1;T<=tc;T++) {
        memset(Map, 0, sizeof(Map));
        memset(visit, false, sizeof(visit));
        fire.clear();

        cin >> w >> h;
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> Map[i][j];

                if(Map[i][j] == '@') {
                    x = i;
                    y = j;
                } else if(Map[i][j] == '*') 
                    fire.push_back(make_pair(i, j));
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