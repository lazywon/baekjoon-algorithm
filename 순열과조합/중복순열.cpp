//5개 중 3개 순서대로 중복 포함하여 나열

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

void dfs(int cnt) {
    if(cnt == 3) {
        print();
        return;
    }

    for(int i=0;i<MAX;i++) {
        select[cnt] = arr[i];
        dfs(cnt+1);
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

    dfs(0);

    return 0;
}