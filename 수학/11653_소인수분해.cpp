#include <bits/stdc++.h>
using namespace std;

void solve(int n)
 {
     for(int i=2;n!=1;i++) {
         while(n%i == 0) {
             cout << i << '\n';
             n /= i;
         }
     }
 }

 void solve2(int n){ //����ȭ�� �ڵ�
  for(int i = 2; i*i <= n; i++){
    while(n % i == 0){
      cout << i << '\n';
      n /= i;
    }
  }
  if(n != 1) cout << n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    solve(n);

    return 0;
}