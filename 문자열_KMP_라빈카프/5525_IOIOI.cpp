/*
    �ϳ��� ���ڿ� �ȿ� ���� ���ڿ��� � ����ִ��� ���ϴ� ����
    ���������� Ǯ�� TLE �߻�, �ð����⵵�� O(N)���� �ٿ�����.
    �ٽ��� O�� ������ ���� Pn���� �ľ��ϴ� ��
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, len;
    string s;
    cin >> n >> len >> s;

    int result = 0;

    for(int i=0;i<s.length();i++) {
        if(s[i+1] == 'O' && s[i+2] == 'I') {
            //O�� ������ �߿�
            int o = 0;
            while(s[i] == 'I' && s[i+1] == 'O') {
                i += 2;
                o++;
                if(s[i] == 'I' && o == n) {
                    o--; //���� o�� Ȯ�� ���ص� ��
                    result++;
                }
            }
        }
    }
    
    cout << result << "\n";

    return 0;
}