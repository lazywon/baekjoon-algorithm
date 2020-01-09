#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    int result = 0;
    for(int i=1;i<=n;i++) {
        d[i] = 1;
        for(int j=1;j<=i;j++) {
            if(arr[j] < arr[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
        if(result < d[i]) {
            result = d[i];
        }
    }
    cout << result << "\n";

    return 0;
}
