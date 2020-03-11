#include <bits/stdc++.h>
using namespace std;

int n, l, ret;
int Map[200][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> Map[i][j];
        }
    }

    //세로 열 밑으로 붙임
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            Map[i+n][j] = Map[n-j-1][i];
        }
    }

    int i, j;
    for(i=0;i<n*2;i++) {
        int count = 1;
        for(j=0;j<n-1;j++) {
            if(Map[i][j] == Map[i][j+1])
                count++;
            else if(Map[i][j] + 1 == Map[i][j+1] && count >= l) 
                count = 1;
            else if(Map[i][j] - 1 ==  Map[i][j+1] && count >= 0)
                count = (1 - l);
            else break;
        }

        if(j == (n-1) && count >= 0)
            ret++;
    }
    cout << ret << "\n";

    return 0;
}
