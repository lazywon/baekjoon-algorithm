#include<bits/stdc++.h>
using namespace std;

int n, result = 987654321;
// int people[5];
int Map[21][21];
int label[21][21];
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

struct COORD {
    int x;
    int y;
};

COORD pos[4];

bool canMakeLine(int x, int y, int d1, int d2) {
    /*
        ���ű��� ��輱�� �׸� �� �ִ��� üũ�غ��� �Լ�.
        - �� �������� ������ ����
        - �������� �־��� ���� üũ
    */

   //????????
   if(x + d1 >= n || y - d1 < 0) return false;
   if(x + d2 >= n || y + d2 >= n) return false;
   if(x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
   if(x + d2 + d1 >= n || y + d2 - d1 < 0) return false;

   return true;
}

void labeling(int a, int b, int c, int d) {
    //���ű��� ��ȣ�� ���̴� �Լ�
    // pos[0], pos[1], po[2], pos[3]�� ������.

    //���� ���� ��� ���ű��� 5������ ����
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            label[i][j] = 5;
        }
    }

    // 1�� ���ű� ����
    // 0����� 1�� �������� x��ǥ �����
    // 0������ 0�� �������� y��ǥ ������
    // ���� ���� 0�� �������� x��ǥ �ຸ�� ũ�ų� �������� ����, ǥ���ؾ��ϴ� ���� ������ ��ĭ�� �پ���.
    int subArea = 0;
    for(int i=0;i<pos[1].x;i++) {
        if(i >= pos[0].x) subArea++;
        for(int j=0;j<=pos[0].y - subArea;j++) {
            label[i][j] = 1;
        }
    }

    // 2�� ���ű� ����
    // 0����� 2�� �������� x��ǥ �����
    // 0������ 0�� �������� y��ǥ ������ �ʳ�����
    // ���� ���� 0�� �������� x��ǥ �ຸ�� Ŀ����, ǥ���ؾ��ϴ� ���� ������ ��ĭ�� �پ���.
    int plusArea = 0;
    for(int i=0;i<=pos[2].x;i++) {
        if(i > pos[0].x) plusArea++;
        for(int j=pos[0].y + 1 + plusArea; j<n; j++) {
            label[i][j] = 2;
        }
    }

    // 3�� ���ű� ����
    // n-1����� 1�� �������� x��ǥ �����
    // 0������ 3�� �������� y��ǥ ������
    // ���� ���� 3�� �������� x��ǥ ������ �۾�����, ǥ���ؾ��ϴ� ���� ������ ��ĭ�� �پ���.
    subArea = 0;
    for(int i=n-1;i>=pos[1].x;i--) {
        if(i < pos[3].x) subArea++;
        for(int j=0; j<pos[3].y - subArea; j++) {
            label[i][j] = 3;
        }
    }

    // 4�� ���ű� ����
    // n-1����� 2�� �������� x��ǥ �����
    // 3�� �������� y��ǥ ������ �ʳ�����
    // ���� ���� 3�� �������� x��ǥ ������ �۾�����, ǥ���ؾ��ϴ� ���� ������ ��ĭ�� �پ���.
    plusArea = 0;
    for(int i=n-1;i>pos[2].x;i--) {
        if(i <= pos[3].x) plusArea++;
        for(int j=pos[3].y + plusArea; j<n; j++) {
            label[i][j] = 4;
        }
    }


    //������ �α��� ����ϰ� �ּҰ� ���ϱ�
    int sum[6] = {0, 0, 0, 0, 0, 0};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            sum[label[i][j]] = sum[label[i][j]] + Map[i][j];
        }
    }

    sort(sum, sum + 6);

    int diff = sum[5] - sum[1];

    result = min(result, diff);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> Map[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=1;j<n;j++) {
            for(int d1=1;d1<=j;d1++) { // 1 ~ y��ǥ
                for(int d2=1;d2<n-j;d2++) { //y��ǥ ~ ���α��̱��� ���� ĭ ��
                    if(canMakeLine(i, j, d1, d2) == true) { // ���� ���������� �� �������� ���� �� �־ ���ű� �׸��� �ִ��� üũ
                        pos[0].x = i; pos[0].y = j;
                        pos[1].x = i + d1; pos[1].y = j - d1;
                        pos[2].x = i + d2; pos[2].y = j + d2;
                        pos[3].x = i + d1 + d2; pos[3].y = j - d1 + d2;
                        labeling(i, j, d1, d2);
                    }
                }
            }
        }
    }

    cout << result << endl;
    

    return 0;
}