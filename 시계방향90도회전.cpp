#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int size = 3;
    int ret[size][size] = {};

    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            ret[i][j] = arr[size - j - 1][i];
        }
    }

    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}