#include <bits/stdc++.h>
using namespace std;

int d[100001];
int arr[100001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int result = 0;
    result = d[0] = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] < d[i-1] + arr[i]) {
            d[i] = d[i-1] + arr[i];
            
        } else {
            d[i] = arr[i];
        }
        result = max(result, d[i]);
        // d[i] = max(arr[i], d[i-1] + arr[i]);
        // result = max(result, d[i]);
    }
    cout << result << "\n";

    return 0;
}