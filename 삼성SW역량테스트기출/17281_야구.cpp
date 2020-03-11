//�𸣰���...

#include <bits/stdc++.h>
using namespace std;

#define MAX 51

int n, result;
int arr[MAX][10]; // �� �̴׿��� ������ �ɷ�ġ ����
bool Select[10];
int order[10];
vector<int> v;

void playGame() {
    int score = 0;
    int startPlayer = 1;
    int baseState[4];
    //0 - Ȩ��, 1 - 1��, 2 - 2��, 3 - 3��
    //base[x] = 1 �̸� ���� x�翡 ����� �ִ�.

    for(int i=1;i<=n;i++) { // n�̴� ����
        int outCnt = 0;
        bool nextIning = false;
        memset(baseState, 0, sizeof(baseState));

        while(1) {
            for(int j=startPlayer;j<=9;j++) {
                int player = arr[i][order[j]];

                if(player == 0) outCnt++; //�ƿ�ĥ ���
                else if(player == 1) {
                    for(int F=3;F>=1;F--) {//�� �翡 �ִ� ������ ��ĭ�� ����
                        if(baseState[F] == 1) {
                            if(F == 3) { // 3�翡 ������ �־��� ���
                                baseState[F] = 0; // Ȩ���� ����
                                score++;
                            } else {
                                baseState[F+1] = 1; //3�簡 �ƴ� �������� 1�羿 ����
                                baseState[F] = 0;
                            }
                        }
                    }
                    baseState[1] = 1;

                }
                else if(player == 2) {
                    for(int F=3;F>=1;F--) {//�� �翡 �ִ� ������ ��ĭ�� ����
                        if(baseState[F] == 1) {
                            if(F == 3 || F == 2) { // 3�� Ȥ�� 2�翡 ������ �־��� ���
                                baseState[F] = 0; // Ȩ���� ����
                                score++;
                            } else {
                                baseState[F+2] = 1; //3�簡 �ƴ� �������� 1�羿 ����
                                baseState[F] = 0;
                            }
                        }
                    }
                    baseState[2] = 1;
                }
                else if(player == 3) {
                    for(int F=3;F>=1;F--) {//�� �翡 �ִ� ������ ��ĭ�� ����
                        if(baseState[F] == 1) {
                            baseState[F] = 0; 
                            score++;
                        }
                    }
                    baseState[3] = 1;
                }
                else { //Ȩ���ϰ��
                    for(int F=1;F<=3;F++) {//
                        if(baseState[F] == 1) {
                            baseState[F] = 0; 
                            score++;
                        }
                    }
                    score++;
                }

                if(outCnt == 3) {
                    startPlayer = j + 1;
                    if(startPlayer == 10) startPlayer = 1;

                    nextIning = true;
                    break;
                }
            }
            if(nextIning == true) break;
            startPlayer = 1;
        }
    }

    result = max(result, score);
}

void dfs(int cnt) {
    if(cnt == 10) {
        playGame();
        return;
    }

    for(int i=1;i<=9;i++) {
        if(Select[i] == true) continue;
        Select[i] = true;
        order[i] = cnt;
        dfs(cnt+1);
        Select[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=9;j++) {
            cin >> arr[i][j];
            //arr[1][2] = 3
            //���� 1�̴׿��� 2�������� 3��Ÿ�� ģ��.
        }
    }

    Select[4] = true;
    order[4] = 1; //4�� Ÿ�ڴ� 1�� �����̴�. 
    
    dfs(2);

    cout << result << "\n";

    return 0;
}