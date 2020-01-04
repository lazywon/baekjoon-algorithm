#include<bits/stdc++.h>
using namespace std;

char mapp[3000][3000]; //3^7 -> 2187

void init() {
    for(int i=0;i<3000;i++) {
        for(int j=0;j<3000;j++) {
            mapp[i][j] = ' ';
        }
    }
}

void solve(int n, int x, int y) {
    if(n == 1) {
        mapp[x][y] = '*';
        return;
    }
    int div = n / 3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i == 1 && j == 1) {
                continue;
            }
            solve(div, x + (div * i), y + (div * j));
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    init();
    solve(n, 0, 0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << mapp[i][j];
        }
        cout << endl;
    }

    return 0;
}

//다시풀어보기!!!!!!ㅜㅜ