//5개 중 3개 순서 상관없이 나열
//{1,2,3} = {2,1,3}

#include <bits/stdc++.h>
using namespace std;

#define MAX 5

int arr[MAX];
bool select[MAX];

void print() {
    for(int i=0;i<MAX;i++) {
        if(select[i] == true) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

void dfs(int idx, int cnt) {
    if(cnt == 3) {
        print();
        return;
    }

    for(int i=idx;i<MAX;i++) {
        if(select[i] == true) continue; // 이미 뽑은 숫자는 지나가세요~
        select[i] = true;

        dfs(i, cnt+1);
        select[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5; 

    dfs(0, 0);

    return 0;
}