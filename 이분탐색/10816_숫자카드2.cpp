/*
#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[500001];

int lowerIdx(int target, int len) {
    int st = 0, en = len;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] < target) 
            st = mid + 1;
        else if(arr[mid] >= target) 
            en = mid;

        if(st == en)
            return st;
    }
    return 0;
}

int upperIdx(int target, int len) {
    int st = 0, en = len;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] <= target) 
            st = mid + 1;
        else if(arr[mid] > target) 
            en = mid;

        if(st == en)
            return en;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    cin >> m;
    for(int i=0;i<m;i++) {
        int num;
        cin >> num;
        int ret = upperIdx(num, n) - lowerIdx(num, n);

        cout << ret << " ";

        //cout << lowerIdx(num, n);
        //cout << upperIdx(num, n);
    }

    return 0;
}
*/

//STL 사용
#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+n);

    int m;
    cin >> m;
    while(m--) {
        int t;
        cin >> t;

        //이상, 초과
        cout << upper_bound(a, a+n, t) - lower_bound(a, a+n, t) << " ";
    }
}