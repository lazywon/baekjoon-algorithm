#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int T=1;T<=n;T++) {
        int L, U, X;
        cin >> L >> U >> X;

        int ret = 0;

        if(X > L && X < U) ret = 0;
        else if(X > U) ret = -1;
        else if(X < L) ret = L - X;

        cout << "#" << T << " " << ret << "\n";
        
    }

    return 0;
}