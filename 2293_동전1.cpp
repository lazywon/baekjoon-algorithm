//�ٽ� Ǯ��!!�̤Ѥ�
//������

#include <bits/stdc++.h>
using namespace std;

int a[105];
int n, k;
vector<int> d1;
vector<int> d2; //�迭���� vector�� ���� ���簡 ���ϴ�.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    d1.resize(k+1); //ũ�� ����
    d2.resize(k+1);

    for(int i=0;i<n;i++) cin >> a[i];

    for(int t=0;t<=k;t+=a[0]) {
        d1[t] = 1;
        //k ������ a[0]�� ����鿡 ���� ��� ����� ���� 1���� ����
    }

    for(int i=1;i<n;i++) {
        fill(d2.begin(), d2.end(), 0); //0���� �ʱ�ȭ
        for(int j=0;j<=k;j++) {
            d2[j] = d1[j];
            if(j >= a[i]) {
                d2[j] += d2[j - a[i]];
            }
        }
        d1 = d2; //����
    }
    cout << d1[k] << "\n";

    return 0;
}
