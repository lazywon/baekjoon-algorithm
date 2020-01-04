#include<bits/stdc++.h>
using namespace std;

// int pow(int a, int b, int c) {
//     int val = 1;
//     while(b--) {
//         val = (val * a) % c;
//     }
//     return val;
// }

long long pow(long long a, long long b, long long c) {
    if(b == 0) return 1;

    long long val = pow(a, b/2, c);
    val = val * val % c;

    if(b % 2 == 0) {
        return val;
    }
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << pow(a, b, c) << "\n";

    return 0;
}