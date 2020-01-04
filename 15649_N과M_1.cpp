// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// int visit[10];
// vector<int> vc;

// void dfs(int count) {
//     if(count == m) {
//         for(int i=0;i<vc.size();i++) {
//             cout << vc[i] << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     for(int i=1;i<=n;i++) {
//         if(visit[i] == 0) {
//             visit[i] = 1;
//             vc.push_back(i);
//             dfs(count + 1);
//             vc.pop_back();
//             visit[i] = 0;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m;
//     dfs(0);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, m;
void func(int* arr, bool* issued, int k) {
    if(k == m) {
        for(int i=0;i<m;i++) cout << arr[i] + 1 << " ";
        cout  << "\n";
        return;
    }

    for(int i=0;i<n;i++) {
        if(!issued[i]) {
            arr[k] = i;
            issued[i] = 1;
            func(arr, issued, k + 1);
            issued[i] = 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int arr[m] = {};
    bool issued[n] = {};

    func(arr, issued, 0);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int a[4] = {1, 2, 3, 4};

//     do {
//         for(int i=0;i<4;i++) cout << a[i] << ' ';
//         cout << "\n";
//     } while (next_permutation(a, a+4));

//     return 0;
// }