#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[10000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i=n-1;i>=0;i--) {
        int t = k / arr[i];
        count += t;
        k -= t * arr[i];
    }

    cout << count << "\n";

    return 0;
}