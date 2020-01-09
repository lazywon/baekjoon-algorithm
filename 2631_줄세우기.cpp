//LIS(���� �κ� ���� ����) ���� �� �����ϴ� �κ� ����
//���� ��� ������������ ���ĵ� �κ��� ��������, ������ �� �ű��
// ��ü�������� ���� ū �����ϴ� �κм����� ���� ����
#include <bits/stdc++.h>
using namespace std;

int n;

int dp[200];
int arr[200];

void dfs() {
    int max = 0;
    for(int i=1;i<=n;i++) {
        dp[i] = 1; //�ڱ��ڽ�

        for(int j=1;j<=i;j++) { //���� ���� Ȯ��
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                //�ش� ������ �� ���� ���̸鼭
                //���� ������ 1������ ũ�Ⱑ ũ��  

                dp[i] = dp[j] + 1; //�ش� �ε��� ũ�� ����
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