#include <bits/stdc++.h>
using namespace std;

int n;
int d[301][2];
int arr[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        cout << arr[0];
        return 0;
    }

    d[0][0] = arr[0];
    d[0][1] = 0;

    d[1][0] = arr[1];
    d[1][1] = arr[0] + arr[1];

    for(int i=2;i<n;i++) {
        d[i][0] = max(d[i-2][0], d[i-2][1]) + arr[i];
        d[i][1] = d[i-1][0] + arr[i];
    }

    cout << max(d[n-1][0], d[n-1][1]);

    return 0;
}
//다시풀기!!