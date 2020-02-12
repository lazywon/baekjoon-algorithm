#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int T=1;T<=10;T++) {
        int n;
        cin >> n;

        char arr[8][8];

        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                cin >> arr[i][j];
            }
        }

        int cnt = 0;

        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                int check1 = 0;
                int check2 = 0;

                for(int k=0;k<=n/2;k++) {
                    if((j + n - 1) < 8) { //가로
                        if(arr[i][j + k] != arr[i][n - k - 1 + j])
                            check1 = 1;
                    } else check1 = 1;
                    
                    if((i + n - 1) < 8) { //세로
                        if(arr[i + k][j] != arr[n - k - 1 + i][j])
                            check2 = 1;
                    } else check2 = 1;
                }
                if(check1 == 0) cnt++;
                if(check2 == 0) cnt++;
                
            }
        }

        cout << "#" << T << " " << cnt << "\n";

    }

    return 0;
}