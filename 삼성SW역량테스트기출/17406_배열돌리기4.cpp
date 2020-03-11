#include <bits/stdc++.h>
using namespace std;

#define MAX 50 + 1
#define K_MAX 6

struct turnInfo {
    int r, c, s;
};

int n, m, k, r, c, s, ans;
int Map[MAX][MAX]; //원본 맵
int cMap[MAX][MAX]; //복사한 맵
bool Select[K_MAX];
vector<turnInfo> v;
vector<int> turnOrder;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void copyMap() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cMap[i][j] = Map[i][j];
        }
    }
}

int changeDir(int cur) {
    if(cur == 0) return 3;
    else if(cur == 1) return 2;
    else if(cur == 2) return 0;
    else if(cur == 3) return 1;

}

void simulation(turnInfo t) {
    //실제 배열 돌려보는 함수
    //1. while문을 통해 각 라인별이 아닌, 한 번에 처리하는 식으로 구현.
    //2. 돌려야 할 사각형의 범위 밖으로 나가는 경우 방향을 바꿔주는 식으로 구현.

    int sx = t.r - t.s;
    int sy = t.c - t.s;
    int ex = t.r + t.s;
    int ey = t.c + t.s;
    int turnCnt = (ex - sx) / 2; // 몇개의 사각형을 돌려야 하는지

    for(int i=0;i<turnCnt;i++) {
        int x = sx;
        int y = sy;
        int tmp = cMap[x][y];
        int d = 2; // 0=동, 1=서, 2=남, 3=북  첫 방향은 남쪽!!
        /*
            첫방향을 남쪽으로 잡은 이유
            시계방향으로 배열이 회전되는 것이기 때문에, 이는 어떻게 보면
            자기 자신을 기준으로 반시계 방향에 있는 값이 자기자신의 자리에 위치하게 된다.
            즉, 시작점을 기준으로 왼쪽 세로변, 하단 가로변, 우측 세로변, 상단 가로변 순으로
            움직이면서 값을 설정해 주었다. 

        */

       while(1) {
           int nx = x + dx[d];
           int ny = y + dy[d];
           //nx, ny는 현재 자기자신을 기준으로 한칸 왼쪽(반시계방향)의 좌표

           if(nx == sx && ny == sy) {//다시 처음 위치로 돌아오게되면
                cMap[x][y] = tmp;
                break;
           }

            //현재 사각형 범위 내에 있는 좌표라면
           if(sx <= nx && nx <= ex-i && sy <= ny && ny <= ey-i) {
               cMap[x][y] = cMap[nx][ny];//자기자신 자리에 반시계방향 좌표 넣어줌
               x = nx;
               y = ny;
           } else {
               //방향을 따라가다 보면 사각형의 범위를 벗어나는 경우가 존재
               //그럴때는 방향을 바꿔준다.
               // 남쪽->동쪽->북쪽->서쪽 순으로
               d = changeDir(d);
           }
       }
       // 그 다음 안쪽 사각형으로 가기.
       //ex) (1, 1) -> (2, 2)
       sx++;
       sy++;
    }
}

int calculate() {
    //돌린 배열에서 모든 행에서 최솟값을 갖는 행의 값 return

    int rVal = 999999999;
    for(int i=1;i<=n;i++) {
        int sum = 0;
        for(int j=1;j<=m;j++) {
            sum += cMap[i][j];
        }
        rVal = min(rVal, sum);
    }
    return rVal;
}

void dfs(int cnt) {
    if(cnt == k) {
        copyMap(); //원본 맵 유지 위해 복사해줌.
        for(int i=0;i<turnOrder.size();i++) {
            int order = turnOrder[i]; //정한 순서대로 
            simulation(v[order]);
        }
        ans = min(ans, calculate());
        return;
    }

    for(int i=0;i<v.size();i++) {
        if(Select[i] == true) continue;

        Select[i] = true;
        turnOrder.push_back(i);
        dfs(cnt + 1);
        turnOrder.pop_back();
        Select[i] = false;

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ans = 987654321;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> Map[i][j];
        }
    }

    for(int i=0;i<k;i++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }

    dfs(0); //순열을 통해 어떤 순서로 돌릴지 순서 정함.
    cout << ans << "\n";

    return 0;
}