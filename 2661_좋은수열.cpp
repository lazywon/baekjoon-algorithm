#include <bits/stdc++.h>
using namespace std;

int n;
string goodNum;

//��Ʈ��ŷ
void dfs(int cnt, char num) {
    if(cnt - 1 == n) {
        cout << goodNum << "\n";
        exit(0); //ó���� ������ ���ڰ� ���� ���� �� / 0�̸� ���� ����. 0�̾ƴѼ� ��� x
        //�ٷ� ����
        
        //return;
    }

    goodNum += num;

    for(int i=1;i<=cnt/2;i++) {
        string a = goodNum.substr(cnt - i, i);
        string b = goodNum.substr(cnt - i * 2, i);

        if(a == b) {
            goodNum.erase(cnt - 1);
            return;
        }
    }

    for(int i=1;i<=3;i++) {
        dfs(cnt+1, i + '0');
    }
    goodNum.erase(cnt - 1); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dfs(1, '1');
    // dfs(1, '2');
    // dfs(1, '3');

    return 0;
}