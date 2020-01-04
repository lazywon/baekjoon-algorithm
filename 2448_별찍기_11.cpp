#include<bits/stdc++.h>
using namespace std;

char DB[][6] = 
{
    "  *  ",
    " * * ",
    "*****"
};

char mapp[3500][6500]; //

void init() {
    for(int i=0;i<3500;i++) {
        for(int j=0;j<6500;j++) {
            mapp[i][j] = ' ';
        }
    }
}

void solve(int n, int x, int y) {
    if(n == 1) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<5;j++) {
                mapp[x + i][y + j] = DB[i][j];
            }
        }
        return;
    }
    solve(n / 2, x, y + 3 * n / 2);
    solve(n / 2, x + 3 * n / 2, y);
    solve(n / 2, x + 3 * n / 2, y + 3 * n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    init();
    solve(n / 3, 0, 0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<2*n-1;j++) {
            if(mapp[i][j] == '*') {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

//다시풀어보기!!!!!!ㅜㅜ