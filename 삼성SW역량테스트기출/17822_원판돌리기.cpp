#include <bits/stdc++.h>
using namespace std;

#define MAX 50 + 5

int n, m, t, sum, total, result, avre;
int circle[MAX][MAX]; //���� ���� ����
int c_circle[MAX][MAX]; // ���� ȸ���� �ӽ� �������
bool visit[MAX][MAX]; // bfs Ž���� �湮üũ
vector<pair<pair<int, int>, int> > cmd;

void copyMap(int a[][MAX], int b[][MAX]) {
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            a[i][j] = b[i][j];
        }
    }
}

void turningCircle(int idx, int dir, int k) {
    //������ ȸ����Ŵ
    //1. ������ ���¸� �ӽ� ���ǿ� ����
    //2. ������ ������ �̿��� �ӽ� ������ ������ �ٲ���
    //3. �ӽ� ������ �ٽ� ������ ����
    copyMap(c_circle, circle);

    if(dir == 0) { //�ð����
        for(int i=0;i<m;i++) {
            int value = circle[idx][i];
            int pos = (i + k) % m;
            c_circle[idx][pos] = value;
        }
    }
    else { //�ݽð����
        for(int i=0;i<m;i++) {
            int value = circle[idx][i];
            int pos = i - k;
            if(pos < 0) pos = pos + m;
            c_circle[idx][pos] = value;
        }
    }
    copyMap(circle, c_circle);
}

bool bfs(int a, int b) {
    //������ ���� �ִ��� ������ Ž���ϴ� �Լ�
    queue<pair<int, int> > q;
    vector<pair<int, int> > v; // ������ ������ ��ġ ������ ����
    q.push(make_pair(a, b));
    v.push_back(make_pair(a, b)); //���� ���� ������ �־��ְ� ����. �ʱ������=1
    visit[a][b] = true;

    while(!q.empty()) {
        int cNum = q.front().first;
        int idx = q.front().second;
        q.pop();

        int leftIdx = idx - 1;
        int rightIdx = idx + 1;
        int leftCircle = cNum - 1;
        int rightCircle = cNum + 1;

        if(leftIdx < 0) leftIdx = m - 1;
        if(rightIdx >= m) rightIdx = rightIdx % m;

        if(circle[cNum][idx] == circle[cNum][leftIdx]) {
            if(visit[cNum][leftIdx] == false) {
                visit[cNum][leftIdx] = true;
                q.push(make_pair(cNum, leftIdx));
                v.push_back(make_pair(cNum, leftIdx));
            }
        }

        if(circle[cNum][idx] == circle[cNum][rightIdx]) {
            if(visit[cNum][rightIdx] == false) {
                visit[cNum][rightIdx] = true;
                q.push(make_pair(cNum, rightIdx));
                v.push_back(make_pair(cNum, rightIdx));
            }
        }

        if(leftCircle > 0) {
            if(circle[cNum][idx] == circle[leftCircle][idx]) {
                if(visit[leftCircle][idx] == false) {
                    visit[leftCircle][idx] = true;
                    q.push(make_pair(leftCircle, idx));
                    v.push_back(make_pair(leftCircle, idx));
                }
            }
        }
        
        if(rightCircle <= n) {
            if(circle[cNum][idx] == circle[rightCircle][idx]) {
                if(visit[rightCircle][idx] == false) {
                    visit[rightCircle][idx] = true;
                    q.push(make_pair(rightCircle, idx));
                    v.push_back(make_pair(rightCircle, idx));
                }
            }
        }
        
    }

    if(v.size() == 1) { // ũ�Ⱑ 1�̴� = ������ ������ �Ȱ��� �������� ����
        return false;
    } else  { // �װԾƴϸ� ������ ������ �Ȱ��������� ���� �ִ�.
        for(int i=0;i<v.size();i++) {
            int x = v[i].first;
            int y = v[i].second;
            circle[x][y] = 0;
        }
        return true;
    }

}

bool checkAdjacency() {
    //������ ���� ���� ���� �ִ��� üũ
    memset(visit, false, sizeof(visit));
    bool flag = false;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(visit[i][j] == false && circle[i][j] != 0) {
                bool t = bfs(i, j);
                if(t == true) flag == true;
            }
        }
    }
    return flag;
}

void changeValue(double avr) {
    //������ ���� ������� ������ ������ ��� ���� ���� ++, -- ����
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(circle[i][j] == 0) continue;
            if((double)(circle[i][j]) > avr) circle[i][j]--;
            else if((double)(circle[i][j]) < avr) circle[i][j]++;
        }
    }
}

pair<int, int> calculate() {
    pair<int, int > r;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            r.first = r.first + circle[i][j];
            if(circle[i][j] != 0) r.second++;
        }
    }
    return r;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            cin >> circle[i][j];
        }
    }
    total = n * m;

    for(int i=0;i<t;i++) {
        int x, d, k;
        cin >>  x >> d >> k;
        cmd.push_back(make_pair(make_pair(x, d), k));
    }

    for(int i=0;i<t;i++) {
        int num = cmd[i].first.first;
        int dir = cmd[i].first.second;
        int k = cmd[i].second;

        for(int j=num; j<=n; j+=num) {
            turningCircle(j, dir, k);
        }

        bool T = checkAdjacency();
        if(T == false) {
            pair<int, int> tmp = calculate();
            tmp = calculate();
            double average = (double)(tmp.first) / (double)(tmp.second);
            changeValue(average);
        }
    }

    result = calculate().first;

    cout << result << "\n";

    return 0;
}