// #include <bits/stdc++.h>
// using namespace std;

// int n, s;
// int cnt = 0;
// int a[21];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> s;
    
//     for(int i=0;i<n;i++) {
//         cin >> a[i];
//     }

//     for(int i=1;i<(1<<n);i++) { //2의 n승
//         int tmp = i;
//         int tot = 0;

//         for(int j=0;j<n;j++) {
//             if(tmp % 2 == 1) {
//                 tot += a[j];
//             }
//             tmp /= 2;
//         }
//         if(tot == s) {
//             cnt++;
//         }
//     }
//     cout << cnt << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, s;
int arr[MAX];
int result = 0;

void numOfSubset(int idx, int sum) {
    sum += arr[idx];

    if(idx >= n) return;
    if(sum == s) result++;

    //해당 숫자를 안더했을 경우
    numOfSubset(idx + 1, sum - arr[idx]);
    //해당 숫자를 더했을 경우
    numOfSubset(idx + 1, sum);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    numOfSubset(0, 0);
    cout << result << "\n";

    return 0;
}