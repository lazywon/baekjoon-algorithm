#include <bits/stdc++.h>
using namespace std;

#define MAX 101

struct sharkInfo {
    int r;
    int c;
    int speed;
    int direct;
    int size;
    int num;
};

int row, col, m, result;
vector<int> Map[MAX][MAX];
vector<sharkInfo> shark; 
int dx[] = {0, -1, 1, 0, 0}; //위, 아래, 오른, 왼
int dy[] = {0, 0, 0, 1, -1}; // 1,2,3,4 여서 0번째 없애기 위해?

bool check() {
    for(int i=0;i<shark.size();i++) {
        if(shark[i].size != 0) return false;
    }
    return true;
}

void fishing(int idx) {
    for(int i=1;i<=row;i++) {
        if(Map[i][idx].size() != 0) {
            result += shark[Map[i][idx][0]].size; //0번째 있는 벡터 값이 가장 큰 상어
            shark[Map[i][idx][0]].size = 0; //상어를 잡았으니 0 으로.
            Map[i][idx].clear(); //vector 초기화
            break;  //가장 땅과 가까이 있는것만 잡기
        }
    }
}

void moveShark() {
    for(int i=0;i<shark.size();i++) {
        if(shark[i].size == 0) continue;
        //상어의 x,y 좌표
        int x = shark[i].r; 
        int y = shark[i].c;
        Map[x][y].clear(); //??왜
    }

    for(int i=0;i<shark.size();i++) {
        if(shark[i].size == 0) continue;
        int x = shark[i].r; 
        int y = shark[i].c;
        int direct = shark[i].direct;
        int speed = shark[i].speed;

        if(direct == 1 || direct == 2) { //위 또는 아래
            int rotate = (row - 1) * 2; // 한바퀴돌았을때 제자리
            if(speed >= rotate) speed = speed % rotate;

            for(int j=0;j<speed;j++) {
                int nx = x + dx[direct];
                int ny = y + dy[direct];

                if(nx < 1) { //반대방향으로 돌기
                    direct = 2;
                    nx += 2;
                }
                if(nx > row) {
                    direct = 1;
                    nx -= 2;
                }
                x = nx;
                y = ny;
            }
        }
        else { // 오른 또는 왼
            int rotate = (col - 1) * 2; // 한바퀴돌았을때 제자리
            if(speed >= rotate) speed = speed % rotate;

            for(int j=0;j<speed;j++) {
                int nx = x + dx[direct];
                int ny = y + dy[direct];

                if(ny < 1) { //반대방향으로 돌기
                    direct = 3;
                    ny += 2;
                }
                if(ny > col) {
                    direct = 4;
                    ny -= 2;
                }
                x = nx;
                y = ny;
            }
        }

        shark[i].r = x;
        shark[i].c = y;
        shark[i].direct = direct;
        Map[x][y].push_back(i); //?

    }
}

bool standard(int a, int b) { // 오름차순
    if(shark[a].size > shark[b].size) return true;
    return false;
}

void killShark() {
    for(int i=1;i<=row;i++) {
        for(int j=1;j<=col;j++) {
            if(Map[i][j].size() > 1) { // 한 칸에 겹치는 상어가 있을때
                sort(Map[i][j].begin(), Map[i][j].end(), standard); //오름차순 정렬

                int liveIdx = Map[i][j][0]; //살아남은 상어
                for(int k=1;k<Map[i][j].size();k++) {
                    shark[Map[i][j][k]].size = 0;
                    shark[Map[i][j][k]].r = -1;
                    shark[Map[i][j][k]].c = -1;
                } // 전부 없애고 위치도 초기화
                Map[i][j].clear();
                Map[i][j].push_back(shark[liveIdx].num); // 살아남은 놈만 벡터에 넣기
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col >> m;

    for(int i=0;i<m;i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.push_back({ r, c, s, d, z, i });
        Map[r][c].push_back(i);
    }

    if(m == 0) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i=1;i<=col;i++) {
        if(check() == true) break;
        fishing(i);
        moveShark();
        killShark();
    }

    cout << result << endl;

    return 0;
}