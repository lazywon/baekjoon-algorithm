//조합에서 {1, 1}처럼 뽑은 숫자를 다시 사용 가능한 것

#include <bits/stdc++.h>
using namespace std;

#define MAX 5

int arr[MAX];
int select[MAX];

void print() {
    for(int i=0;i<3;i++) {
        cout << select[i] << " ";
    }
    cout << "\n";
}

void dfs(int idx, int cnt) {
    if(cnt == 3) {
        print();
        return;
    }

    for(int i=idx;i<MAX;i++) {
        select[cnt] = arr[i]; // cnt번째 뽑은 수는 arr[i]이다.
        dfs(i, cnt+1);
        
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