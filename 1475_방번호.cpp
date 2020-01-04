#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string num = to_string(n);
    vector<int> v(9);

    for(int i=0;i<num.length();i++) {
        int res = num.at(i) - 48;
        if(res == 9) {
            v[6]++;
            continue;
        }
        v[res]++;
    }

    int max = 0;
    int max_val = 0;
    for(int i=0;i<v.size();i++) {
        if(max < v[i]) {
            max = v[i];
            max_val = i;
        }  
    }

    int max2 = 0;
    if(max_val == 6) {
        if(max % 2 == 0) {
            max2 = max / 2;
        } else {
            max2 = (max) / 2 + 1;
        }
        
        for(int i=0;i<v.size();i++) {
            if(i == 6) {
                continue;
            }
            if(max2 < v[i]) {
                max2 = v[i];
            }  
        }

        cout << max2 << "\n";
    } else {
        cout << max << "\n";
    }


    return 0;
}