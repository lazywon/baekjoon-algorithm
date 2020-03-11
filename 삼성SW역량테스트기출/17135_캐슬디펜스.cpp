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

bool allKill() { // ���� �Ѹ� ���������� ������
    bool flag = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(cMap[i][j] == 1) { // ���࿡ ���� �����Ѵٸ�
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

bool standard(enemyInfo A, enemyInfo B) { //sorting ����
    // �Ÿ��� �� ª���� ����
    // �Ÿ��� ���ٸ� ���� ���ʿ� �ִ� ���� ��ǥ ������
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
    pair<int, int> arrowTarget[3]; ///�� �ü����� �� ������ ��ǥ (�ߺ� ���� �� �־ ���� ����)

    for(int i=0;i<pos.size();i++) { 
        // �ü��� ��ġ
        int x = n;
        int y = pos[i]; // 0 ~ m-1 ����
        vector<enemyInfo> killEnemyTmp;//�����Ÿ� ���� �ִ� ����

        for(int j=0;j<v.size();j++) { //������ ����ŭ
            //���� ��ġ
            int xx = v[j].first;
            int yy = v[j].second;

            int distance = dist(x, y, xx, yy);
            if(distance <= d) {
                enemyInfo tmp;
                tmp.x = xx;
                tmp.y = yy;
                tmp.dist = distance;
                killEnemyTmp.push_back(tmp);//�����Ÿ� ���� �ִ� ��
            }
        }

        int possibleEnemy = killEnemyTmp.size();
        if(possibleEnemy > 1) {
            sort(killEnemyTmp.begin(), killEnemyTmp.end(), standard);
            //�Ÿ���, �Ÿ��� ������ ���ʼ� sort �ϸ� 0 ��°�� ���� ū �켱����
            arrowTarget[i].first = killEnemyTmp[0].x;
            arrowTarget[i].second = killEnemyTmp[0].y;
        } else if(possibleEnemy == 1) {
            arrowTarget[i].first = killEnemyTmp[0].x;
            arrowTarget[i].second = killEnemyTmp[0].y;
        } else { // ���ǿ� �´� ���� �Ѹ� ������
            arrowTarget[i].first = -1;
            arrowTarget[i].second = -1;
        }
    }

    for(int i=0;i<3;i++) {
        int x = arrowTarget[i].first;
        int y = arrowTarget[i].second;

        if(x == -1 && y == -1) continue;
        if(visit[x][y] == false) { // �ߺ� ���ϱ� ����
            visit[x][y] = true;
            cMap[x][y] = 0; // ���̱�
            tmpAns++; //���� ���� �� ����
        }
    }
}

void moveEnemy() {
    //�� �Ʒ��� ��ĭ�� �̵�
    // �̶� ���� �� ���� �̵��ϸ� ���� �ٲ�����. ������ �Ʒ��� ������ �ű� ����. 
    // �׷��� �ؿ�������
    for(int i=v.size()-1;i>=0;i--) {
        int x = v[i].first;
        int y = v[i].second;

        if(cMap[x][y] == 0) continue;
        if(x == n-1) { // ������ ���� ������ �� �����Ƿ�
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

        if(allKill() == true) break; //���� ��� ������ ���� �ϴ� ��
        attack(); //�ü��� �������� �� ���̱�
        moveEnemy();
    }
}

void dfs(int idx, int cnt) { //�������� �ü��� ��ġ ���ϱ�
    if(cnt == 3) {
        tmpAns = 0;
        killEnemy();
        ans = max(ans, tmpAns);
        return;
    }

    for(int i=idx;i<m;i++) {
        if(Select[i] == true) continue; // �̹� ���� ���ڴ� ����������~
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