#include <bits/stdc++.h>
using namespace std;

#define MAX 50 + 1
#define K_MAX 6

struct turnInfo {
    int r, c, s;
};

int n, m, k, r, c, s, ans;
int Map[MAX][MAX]; //���� ��
int cMap[MAX][MAX]; //������ ��
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
    //���� �迭 �������� �Լ�
    //1. while���� ���� �� ���κ��� �ƴ�, �� ���� ó���ϴ� ������ ����.
    //2. ������ �� �簢���� ���� ������ ������ ��� ������ �ٲ��ִ� ������ ����.

    int sx = t.r - t.s;
    int sy = t.c - t.s;
    int ex = t.r + t.s;
    int ey = t.c + t.s;
    int turnCnt = (ex - sx) / 2; // ��� �簢���� ������ �ϴ���

    for(int i=0;i<turnCnt;i++) {
        int x = sx;
        int y = sy;
        int tmp = cMap[x][y];
        int d = 2; // 0=��, 1=��, 2=��, 3=��  ù ������ ����!!
        /*
            ù������ �������� ���� ����
            �ð�������� �迭�� ȸ���Ǵ� ���̱� ������, �̴� ��� ����
            �ڱ� �ڽ��� �������� �ݽð� ���⿡ �ִ� ���� �ڱ��ڽ��� �ڸ��� ��ġ�ϰ� �ȴ�.
            ��, �������� �������� ���� ���κ�, �ϴ� ���κ�, ���� ���κ�, ��� ���κ� ������
            �����̸鼭 ���� ������ �־���. 

        */

       while(1) {
           int nx = x + dx[d];
           int ny = y + dy[d];
           //nx, ny�� ���� �ڱ��ڽ��� �������� ��ĭ ����(�ݽð����)�� ��ǥ

           if(nx == sx && ny == sy) {//�ٽ� ó�� ��ġ�� ���ƿ��ԵǸ�
                cMap[x][y] = tmp;
                break;
           }

            //���� �簢�� ���� ���� �ִ� ��ǥ���
           if(sx <= nx && nx <= ex-i && sy <= ny && ny <= ey-i) {
               cMap[x][y] = cMap[nx][ny];//�ڱ��ڽ� �ڸ��� �ݽð���� ��ǥ �־���
               x = nx;
               y = ny;
           } else {
               //������ ���󰡴� ���� �簢���� ������ ����� ��찡 ����
               //�׷����� ������ �ٲ��ش�.
               // ����->����->����->���� ������
               d = changeDir(d);
           }
       }
       // �� ���� ���� �簢������ ����.
       //ex) (1, 1) -> (2, 2)
       sx++;
       sy++;
    }
}

int calculate() {
    //���� �迭���� ��� �࿡�� �ּڰ��� ���� ���� �� return

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
        copyMap(); //���� �� ���� ���� ��������.
        for(int i=0;i<turnOrder.size();i++) {
            int order = turnOrder[i]; //���� ������� 
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

    dfs(0); //������ ���� � ������ ������ ���� ����.
    cout << ans << "\n";

    return 0;
}