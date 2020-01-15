// #include <bits/stdc++.h>
// using namespace std;
// int ret;

// 시간초과
// int factorial(int n) {
//     if(n == 1) return 1;

//     return n * factorial(n-1);
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;

//     ret = (factorial(n-k) * factorial(k));
//     cout << factorial(n) / ret << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  int ret = 1;
  for(int i = 1; i <= n; i++) ret *= i;
  for(int i = 1; i <= k; i++) ret /= i;
  for(int i = 1; i <= n-k; i++) ret /= i;
  cout << ret;
}