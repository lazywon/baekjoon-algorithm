//다시 풀것!!ㅜㅡㅜ
//노이해

#include <bits/stdc++.h>
using namespace std;

int a[105];
int n, k;
vector<int> d1;
vector<int> d2; //배열보다 vector가 값의 복사가 편하다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    d1.resize(k+1); //크기 변경
    d2.resize(k+1);

    for(int i=0;i<n;i++) cin >> a[i];

    for(int t=0;t<=k;t+=a[0]) {
        d1[t] = 1;
        //k 이하의 a[0]의 배수들에 대해 모두 경우의 수가 1가지 있음
    }

    for(int i=1;i<n;i++) {
        fill(d2.begin(), d2.end(), 0); //0으로 초기화
        for(int j=0;j<=k;j++) {
            d2[j] = d1[j];
            if(j >= a[i]) {
                d2[j] += d2[j - a[i]];
            }
        }
        d1 = d2; //복사
    }
    cout << d1[k] << "\n";

    return 0;
}
