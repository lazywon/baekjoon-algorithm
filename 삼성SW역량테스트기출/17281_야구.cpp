//모르겠음...

#include <bits/stdc++.h>
using namespace std;

#define MAX 51

int n, result;
int arr[MAX][10]; // 각 이닝에서 선수들 능력치 저장
bool Select[10];
int order[10];
vector<int> v;

void playGame() {
    int score = 0;
    int startPlayer = 1;
    int baseState[4];
    //0 - 홈런, 1 - 1루, 2 - 2루, 3 - 3루
    //base[x] = 1 이면 현재 x루에 사람이 있다.

    for(int i=1;i<=n;i++) { // n이닝 동안
        int outCnt = 0;
        bool nextIning = false;
        memset(baseState, 0, sizeof(baseState));

        while(1) {
            for(int j=startPlayer;j<=9;j++) {
                int player = arr[i][order[j]];

                if(player == 0) outCnt++; //아웃칠 경우
                else if(player == 1) {
                    for(int F=3;F>=1;F--) {//각 루에 있던 선수들 한칸씩 전진
                        if(baseState[F] == 1) {
                            if(F == 3) { // 3루에 선수가 있었을 경우
                                baseState[F] = 0; // 홈으로 들어가고
                                score++;
                            } else {
                                baseState[F+1] = 1; //3루가 아닌 선수들은 1루씩 전진
                                baseState[F] = 0;
                            }
                        }
                    }
                    baseState[1] = 1;

                }
                else if(player == 2) {
                    for(int F=3;F>=1;F--) {//각 루에 있던 선수들 한칸씩 전진
                        if(baseState[F] == 1) {
                            if(F == 3 || F == 2) { // 3루 혹은 2루에 선수가 있었을 경우
                                baseState[F] = 0; // 홈으로 들어가고
                                score++;
                            } else {
                                baseState[F+2] = 1; //3루가 아닌 선수들은 1루씩 전진
                                baseState[F] = 0;
                            }
                        }
                    }
                    baseState[2] = 1;
                }
                else if(player == 3) {
                    for(int F=3;F>=1;F--) {//각 루에 있던 선수들 한칸씩 전진
                        if(baseState[F] == 1) {
                            baseState[F] = 0; 
                            score++;
                        }
                    }
                    baseState[3] = 1;
                }
                else { //홈런일경우
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
            //뜻은 1이닝에서 2번선수는 3루타를 친다.
        }
    }

    Select[4] = true;
    order[4] = 1; //4번 타자는 1번 선수이다. 
    
    dfs(2);

    cout << result << "\n";

    return 0;
}