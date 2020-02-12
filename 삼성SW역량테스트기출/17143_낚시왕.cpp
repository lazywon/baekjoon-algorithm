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
int dx[] = {0, -1, 1, 0, 0}; //��, �Ʒ�, ����, ��
int dy[] = {0, 0, 0, 1, -1}; // 1,2,3,4 ���� 0��° ���ֱ� ����?

bool check() {
    for(int i=0;i<shark.size();i++) {
        if(shark[i].size != 0) return false;
    }
    return true;
}

void fishing(int idx) {
    for(int i=1;i<=row;i++) {
        if(Map[i][idx].size() != 0) {
            result += shark[Map[i][idx][0]].size; //0��° �ִ� ���� ���� ���� ū ���
            shark[Map[i][idx][0]].size = 0; //�� ������� 0 ����.
            Map[i][idx].clear(); //vector �ʱ�ȭ
            break;  //���� ���� ������ �ִ°͸� ���
        }
    }
}

void moveShark() {
    for(int i=0;i<shark.size();i++) {
        if(shark[i].size == 0) continue;
        //����� x,y ��ǥ
        int x = shark[i].r; 
        int y = shark[i].c;
        Map[x][y].clear(); //??��
    }

    for(int i=0;i<shark.size();i++) {
        if(shark[i].size == 0) continue;
        int x = shark[i].r; 
        int y = shark[i].c;
        int direct = shark[i].direct;
        int speed = shark[i].speed;

        if(direct == 1 || direct == 2) { //�� �Ǵ� �Ʒ�
            int rotate = (row - 1) * 2; // �ѹ����������� ���ڸ�
            if(speed >= rotate) speed = speed % rotate;

            for(int j=0;j<speed;j++) {
                int nx = x + dx[direct];
                int ny = y + dy[direct];

                if(nx < 1) { //�ݴ�������� ����
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
        else { // ���� �Ǵ� ��
            int rotate = (col - 1) * 2; // �ѹ����������� ���ڸ�
            if(speed >= rotate) speed = speed % rotate;

            for(int j=0;j<speed;j++) {
                int nx = x + dx[direct];
                int ny = y + dy[direct];

                if(ny < 1) { //�ݴ�������� ����
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

bool standard(int a, int b) { // ��������
    if(shark[a].size > shark[b].size) return true;
    return false;
}

void killShark() {
    for(int i=1;i<=row;i++) {
        for(int j=1;j<=col;j++) {
            if(Map[i][j].size() > 1) { // �� ĭ�� ��ġ�� �� ������
                sort(Map[i][j].begin(), Map[i][j].end(), standard); //�������� ����

                int liveIdx = Map[i][j][0]; //��Ƴ��� ���
                for(int k=1;k<Map[i][j].size();k++) {
                    shark[Map[i][j][k]].size = 0;
                    shark[Map[i][j][k]].r = -1;
                    shark[Map[i][j][k]].c = -1;
                } // ���� ���ְ� ��ġ�� �ʱ�ȭ
                Map[i][j].clear();
                Map[i][j].push_back(shark[liveIdx].num); // ��Ƴ��� �� ���Ϳ� �ֱ�
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