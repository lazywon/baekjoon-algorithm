#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    sum = a * b * c;

    string num = to_string(sum);

    vector<char> v(10);

    for(int i=0;i<num.length();i++) {
        char number = num.at(i);
        int res = number - 48;
        v[res]++;
    }

    for(int i=0;i<v.size();i++) {
        int ret = v[i];
        cout << ret << "\n";
    }

    return 0;
}