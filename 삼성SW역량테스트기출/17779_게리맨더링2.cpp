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
        선거구의 경계선을 그릴 수 있는지 체크해보는 함수.
        - 각 꼭지점의 범위를 생각
        - 문제에서 주어진 조건 체크
    */

   //????????
   if(x + d1 >= n || y - d1 < 0) return false;
   if(x + d2 >= n || y + d2 >= n) return false;
   if(x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
   if(x + d2 + d1 >= n || y + d2 - d1 < 0) return false;

   return true;
}

void labeling(int a, int b, int c, int d) {
    //선거구의 번호를 붙이는 함수
    // pos[0], pos[1], po[2], pos[3]은 꼭짓점.

    //가장 먼저 모든 선거구를 5번으로 설정
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            label[i][j] = 5;
        }
    }

    // 1번 선거구 설정
    // 0행부터 1번 꼭짓점의 x좌표 행까지
    // 0열부터 0번 꼭짓점의 y좌표 열까지
    // 행의 값이 0번 꼭짓점의 x좌표 행보다 크거나 같아지는 순간, 표시해야하는 열의 개수가 한칸씩 줄어든다.
    int subArea = 0;
    for(int i=0;i<pos[1].x;i++) {
        if(i >= pos[0].x) subArea++;
        for(int j=0;j<=pos[0].y - subArea;j++) {
            label[i][j] = 1;
        }
    }

    // 2번 선거구 설정
    // 0행부터 2번 꼭짓점의 x좌표 행까지
    // 0열부터 0번 꼭짓점의 y좌표 열부터 맵끝까지
    // 행의 값이 0번 꼭짓점의 x좌표 행보다 커지면, 표시해야하는 열의 개수가 한칸씩 줄어든다.
    int plusArea = 0;
    for(int i=0;i<=pos[2].x;i++) {
        if(i > pos[0].x) plusArea++;
        for(int j=pos[0].y + 1 + plusArea; j<n; j++) {
            label[i][j] = 2;
        }
    }

    // 3번 선거구 설정
    // n-1행부터 1번 꼭짓점의 x좌표 행까지
    // 0열부터 3번 꼭짓점의 y좌표 열까지
    // 행의 값이 3번 꼭짓점의 x좌표 값보다 작아지면, 표시해야하는 열의 개수가 한칸씩 줄어든다.
    subArea = 0;
    for(int i=n-1;i>=pos[1].x;i--) {
        if(i < pos[3].x) subArea++;
        for(int j=0; j<pos[3].y - subArea; j++) {
            label[i][j] = 3;
        }
    }

    // 4번 선거구 설정
    // n-1행부터 2번 꼭짓점의 x좌표 행까지
    // 3번 꼭짓점의 y좌표 열부터 맵끝까지
    // 행의 값이 3번 꼭짓점의 x좌표 값보다 작아지면, 표시해야하는 열의 개수가 한칸씩 줄어든다.
    plusArea = 0;
    for(int i=n-1;i>pos[2].x;i--) {
        if(i <= pos[3].x) plusArea++;
        for(int j=pos[3].y + plusArea; j<n; j++) {
            label[i][j] = 4;
        }
    }


    //실제로 인구수 계산하고 최소값 구하기
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
            for(int d1=1;d1<=j;d1++) { // 1 ~ y좌표
                for(int d2=1;d2<n-j;d2++) { //y좌표 ~ 가로길이까지 남은 칸 수
                    if(canMakeLine(i, j, d1, d2) == true) { // 위의 범위만으로 다 충족하지 않을 수 있어서 선거구 그릴수 있는지 체크
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