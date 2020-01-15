#include <bits/stdc++.h>
using namespace std;

//최적화한 에라토스테네스의 체
vector<int> allPrime(int n) {
    vector<int> ret;
    //int state[n+1];
    vector<bool> state(n+1, true);
    state[1] = 0;

    //for(int i=2;i<=n;i++) state[i] = 1;
    for(int i=2;i*i<=n;i++) {
        if(!state[i]) continue;
        // for(int j=i*2;j<=n;j+=i) state[j] = 0;
        for(int j=i*i;j<=n;j+=i) state[j] = 0;
    }

    for(int i=1;i<=n;i++) {
        if(state[i]) ret.push_back(i);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 100;

    vector<int> result(n);
    result = allPrime(n);

    for(int i=0;i<result.size();i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}