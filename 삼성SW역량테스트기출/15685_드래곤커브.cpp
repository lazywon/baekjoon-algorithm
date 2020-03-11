//문제이해 노이해........

#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int n, x, y, d, g, Sx, Sy;
int Map[MAX][MAX];

int dx[] = {0, -1, 0, 1};  // 오, 위, 왼, 아
int dy[] = {1, 0, -1, 0};

vector<int> dirInfo;

//
void makeDragonCurve() {
    int s = dirInfo.size(); //이전 세대 방향 정보 담고있는 vector
    for(int i=s-1;i>=0;i--) { // 이전 세대 방향 정보 역순으로 탐색
        int nd = (dirInfo[i] + 1) % 4; //다음 세대에서 추가되는 선분의 방향정보 -> 90도 회전한것
        x = x + dx[nd];
        y = y + dy[nd];
        Map[x][y] = 1;

        dirInfo.push_back(nd);
    }
}

void countSquare() {
    int cnt = 0;
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            if(Map[i][j] == 1 && Map[i+1][j] == 1 && 
                Map[i][j+1] == 1 && Map[i+1][j+1] == 1) {
                    cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> y >> x >> d >> g;

        dirInfo.clear();

        Map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        Map[x][y] = 1;

        dirInfo.push_back(d);

        for(int j=0;j<g;j++) {
            makeDragonCurve();
        }

    }

    countSquare();

    return 0;
}