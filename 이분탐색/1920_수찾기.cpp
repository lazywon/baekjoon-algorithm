/*
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];

int BinarySearch(int target, int len) {
    int st = 0, en = len - 1;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] < target)
            st = mid + 1;
        else if(arr[mid] > target)
            en = mid - 1;
        else
            return 1;
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
    int tmp[m];
    
    for(int i=0;i<m;i++) {
        int num;
        cin >> num;
        tmp[i] = BinarySearch(num, n);

    } 
    for(int i=0;i<m;i++) {
        cout << tmp[i] << "\n";
    }


    return 0;
}
*/

//STL »ç¿ë
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a,a+n);

  int m;
  cin >> m;

  while(m--){
    int t;
    cin >> t;
    cout << binary_search(a,a+n,t) << '\n';
  }    
}