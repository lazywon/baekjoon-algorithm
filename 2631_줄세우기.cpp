//LIS(최장 부분 증가 수열) 가장 긴 증가하는 부분 수열
//가장 길게 오름차순으로 정렬된 부분을 기준으로, 나머지 값 옮기기
// 전체개수에서 가장 큰 증가하는 부분수열의 개수 빼기
#include <bits/stdc++.h>
using namespace std;

int n;

int dp[200];
int arr[200];

void dfs() {
    int max = 0;
    for(int i=1;i<=n;i++) {
        dp[i] = 1; //자기자신

        for(int j=1;j<=i;j++) { //이전 값들 확인
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                //해당 값보다 더 작은 값이면서
                //기존 값보다 1증가한 크기가 크면  

                dp[i] = dp[j] + 1; //해당 인덱스 크기 갱신
            }
        }

        if(max < dp[i]) {
            max = dp[i];
        }
    }

    cout << n - max << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    dfs();

    return 0;
}