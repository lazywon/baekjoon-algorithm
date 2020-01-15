#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int count = 0;

    // for(int i=1;i<=n;i++) {

    //     for(int j=5;j<=n;j*=5) {
    //         if(i % j == 0) {
    //             count++;
    //         }
    //     }
    // }

    while(n > 0) {
        n /= 5;
        count += n;
    }

    cout << count << "\n";

    return 0;
}