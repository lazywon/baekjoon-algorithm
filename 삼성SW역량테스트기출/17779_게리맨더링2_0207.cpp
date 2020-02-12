#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n;
int arr[20][20];
int mark[20][20];

void fill(int r, int c, int value) {
    if(r < 0 || r > n-1 || c < 0 || c > n-1) return; // 범위밖인경우
    if(mark[r][c] != 0) return; //빈공간 아닌경우

    mark[r][c] = value;

    fill(r-1, c, value); //상
    fill(r+1, c, value); //하
    fill(r, c-1, value); //좌
    fill(r, c+1, value); //우
}

int solve() {
    int ret = INF;

    /*
                * (x, y)
            *       *
(x+d1, y-d1)    *   (x+d2, y+d2)
        (x+d1+d2, y-d1+d2)
    */    

    for(int x=0; x<=n-3; x++) {
        for(int y=1;y<=n-2;y++) {
            for(int d1=1; x+d1<=n-2 && y-d1>=0; d1++) {
                for(int d2=1; x+d1+d2 <= n-1 &&  y+d2 <= n-1; d2++) {
                    // 경계선 그리기 (1~5까지)

                    memset(mark, 0, sizeof(mark)); // 재사용

                    //5번 경계선 그리기
                    for(int i=0;i<=d1;i++) { // 1번과 4번 
                        mark[x+i][y-i] = 5; 
                        mark[x+d2+i][y+d2-i] = 5;
                    }

                    for(int i=0;i<=d2;i++) { // 2번과 3번
                        mark[x+i][y+i] = 5;
                        mark[x+d1+i][y-d1+i]= 5;
                    }

                    //1번 그리기
                    for(int r=x-1;r>=0;r--) 
                        mark[r][y] = 1;

                    //2번
                    for(int c=y+d2+1;c<n;c++) {
                        mark[x+d2][c] = 2;
                    }

                    //3번
                    for(int c=y-d1-1;c>=0;c--) {
                        mark[x+d1][c] = 3;
                    }

                    //4번
                    for(int r=x+d1+d2+1;r<n;r++) {
                        mark[r][y-d1+d2] = 4;
                    }

                    fill(0, 0, 1); // 1
                    fill(0, n-1, 2); // 2
                    fill(n-1, 0, 3); // 3
                    fill(n-1, n-1, 4); // 4

                    //5번선거구는 0번이라고 생각.
                    
                    int people[6] = {0}; //0으로 초기화됨.
                    for(int r=0;r<n;r++) {
                        for(int c=0;c<n;c++) {
                            people[mark[r][c]] += arr[r][c];
                        }
                    }

                    people[5] += people[0];
                    int minP=INF, maxP=0;
                    for(int i=1;i<=5;i++) {
                        minP = min(minP, people[i]);
                        maxP = max(maxP, people[i]);
                    }

                    ret = min(ret, maxP - minP);
                }
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}