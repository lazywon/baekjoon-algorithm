#include <bits/stdc++.h>
using namespace std;

#define MAX 11

int n, m, k;
vector<int> Map[MAX][MAX];
int energy[MAX][MAX];
int insertEnergy[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springAndSummer() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(Map[i][j].size() != 0) {
                vector<int> tmp;
                int dieEnergy = 0;

                sort(Map[i][j].begin(), Map[i][j].end()); //오름차순 정렬

                for(int k=0;k<Map[i][j].size();k++) {
                    if(energy[i][j] >= Map[i][j][k]) {
                        energy[i][j] -= Map[i][j][k];
                        Map[i][j][k] += 1;
                        tmp.push_back(Map[i][j][k]);
                    } else {
                        dieEnergy += (Map[i][j][k] / 2);
                    }
                }
                Map[i][j].clear();
                for(int k=0;k<tmp.size();k++) {
                    Map[i][j].push_back(tmp[k]);
                }

                energy[i][j] += dieEnergy;
            }
        }
    }
}

void fall() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(Map[i][j].size() == 0) continue;
            for(int k=0;k<Map[i][j].size();k++) {
                if(Map[i][j][k] % 5 == 0) {
                    for(int dir=0;dir<8;dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if(nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
                            Map[nx][ny].push_back(1); 
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            energy[i][j] += insertEnergy[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 땅크기, 나무 수, K년
    cin >> n >> m >> k;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> insertEnergy[i][j];
            energy[i][j] = 5;
        }
    }

    int x, y, age;

    for(int i=0;i<m;i++) {
        cin >> x >> y >> age;
        Map[x][y].push_back(age);
    }

    for(int i=0;i<k;i++) {
        springAndSummer();
        fall();
        winter();
    }

    int result = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            result += Map[i][j].size();
        }
    }

    cout << result << "\n";
    


    return 0;
}