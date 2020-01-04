#include <bits/stdc++.h>
using namespace std;

int n, m;
int arrA[1000001];
int arrB[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> arrA[i];
    }

    for(int i=0;i<m;i++) {
        cin >> arrB[i];
    }

    int size = n + m;
    //int ret[size];

    vector<int> vc;

    int idx1 = 0;
    int idx2 = 0;
    while(idx1 < n && idx2 < m) {
        if(arrA[idx1] < arrB[idx2]) {
            vc.push_back(arrA[idx1]);
            
            idx1++;
        } else {
            vc.push_back(arrB[idx2]);
            idx2++;
        }
    }

    while(idx1 < n) {
        vc.push_back(arrA[idx1]);
        idx1++;
    }

    while(idx2 < m) {
        vc.push_back(arrB[idx2]);
        idx2++;
    }

    for(int i=0;i<size;i++) {
        cout << vc[i] << " ";
    }
    cout << "\n";

    return 0;
}