#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve(int n, int k)
 {
     vector<int> ret;
     for(int i=1;i<=n;i++) {
         if(n%i == 0)
            ret.push_back(i);
     }
     
     cout << ret[k-1] << "\n";
 }

vector<int> divisor(int n) {
    vector<int> ret;
    for(int i=1;i*i<=n;i++) {
        if(n%i == 0) ret.push_back(i);
    }

    for(int i=ret.size()-1;i>=0;i--) {
        if(ret[i]*ret[i] == n) continue;
        ret.push_back(n / ret[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    //solve(n, k);
    vector<int> result;
    result = divisor(n);

    if(result.size() < k) 
        cout << 0;
    else 
        cout << result[k-1];

    return 0;
}