#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001]; //잘~~~보고 넣기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int ans = 0;

    for(int i=1;i<=n;i++) {
        int tmp = arr[n-i] * i;
        ans = max(ans, tmp);
        //ans = max(ans, arr[n-i] * i);
    }

    cout << ans << "\n";

    return 0;
}