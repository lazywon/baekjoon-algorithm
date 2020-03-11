#include <bits/stdc++.h>
using namespace std;

struct enemyInfo {
    int x, y, dist;
};

int n, m, d, ans, tmpAns;
int Map[16][16];
int cMap[16][16];
bool visit[16][16];
bool Select[16];
vector<pair<int, int> > v;
vector<int> pos;

void copyMap() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cMap[i][j] = Map[i][j];
        }
    }
}

bool allKill() { // 적이 한명도 없을때까지 돌리기
    bool flag = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(cMap[i][j] == 1) { // 만약에 적이 존재한다면
                v.push_back(make_pair(i, j));
                flag = false;
            }
        }
    }
    return flag;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool standard(enemyInfo A, enemyInfo B) { //sorting 구현
    // 거리가 더 짧은것 부터
    // 거리가 같다면 가장 왼쪽에 있는 적의 좌표 순으로
    if(A.dist <= B.dist) {
        if(A.dist == B.dist) {
            if(A.y < B.y) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void attack() {
    pair<int, int> arrowTarget[3]; ///각 궁수들이 쏜 적군의 좌표 (중복 있을 수 있어서 구분 위해)

    for(int i=0;i<pos.size();i++) { 
        // 궁수의 위치
        int x = n;
        int y = pos[i]; // 0 ~ m-1 까지
        vector<enemyInfo> killEnemyTmp;//사정거리 내에 있는 적들

        for(int j=0;j<v.size();j++) { //적들의 수만큼
            //적의 위치
            int xx = v[j].first;
            int yy = v[j].second;

            int distance = dist(x, y, xx, yy);
            if(distance <= d) {
                enemyInfo tmp;
                tmp.x = xx;
                tmp.y = yy;
                tmp.dist = distance;
                killEnemyTmp.push_back(tmp);//사정거리 내에 있는 적
            }
        }

        int possibleEnemy = killEnemyTmp.size();
        if(possibleEnemy > 1) {
            sort(killEnemyTmp.begin(), killEnemyTmp.end(), standard);
            //거리순, 거리가 같으면 왼쪽순 sort 하면 0 번째가 가장 큰 우선순위
            arrowTarget[i].first = killEnemyTmp[0].x;
            arrowTarget[i].second = killEnemyTmp[0].y;
        } else if(possibleEnemy == 1) {
            arrowTarget[i].first = killEnemyTmp[0].x;
            arrowTarget[i].second = killEnemyTmp[0].y;
        } else { // 조건에 맞는 적이 한명도 없으면
            arrowTarget[i].first = -1;
            arrowTarget[i].second = -1;
        }
    }

    for(int i=0;i<3;i++) {
        int x = arrowTarget[i].first;
        int y = arrowTarget[i].second;

        if(x == -1 && y == -1) continue;
        if(visit[x][y] == false) { // 중복 피하기 위해
            visit[x][y] = true;
            cMap[x][y] = 0; // 죽이기
            tmpAns++; //죽인 적의 수 증가
        }
    }
}

void moveEnemy() {
    //적 아래로 한칸씩 이동
    // 이때 위에 줄 부터 이동하면 값이 바껴버림. 위에서 아래로 내리는 거기 때문. 
    // 그래서 밑에서부터
    for(int i=v.size()-1;i>=0;i--) {
        int x = v[i].first;
        int y = v[i].second;

        if(cMap[x][y] == 0) continue;
        if(x == n-1) { // 마지막 줄은 내려갈 곳 없으므로
            cMap[x][y] = 0;
        } else {
            cMap[x][y] = 0;
            cMap[x+1][y] = 1;
        }
    }
}

void killEnemy() {
    copyMap();
    while(1) {
        v.clear();
        memset(visit, false, sizeof(visit));

        if(allKill() == true) break; //적이 모두 죽을때 까지 하는 것
        attack(); //궁수의 공격으로 적 죽이기
        moveEnemy();
    }
}

void dfs(int idx, int cnt) { //조합으로 궁수의 위치 정하기
    if(cnt == 3) {
        tmpAns = 0;
        killEnemy();
        ans = max(ans, tmpAns);
        return;
    }

    for(int i=idx;i<m;i++) {
        if(Select[i] == true) continue; // 이미 뽑은 숫자는 지나가세요~
        Select[i] = true;
        pos.push_back(i);
        dfs(i, cnt+1);
        pos.pop_back();
        Select[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> Map[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}