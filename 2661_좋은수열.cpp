#include <bits/stdc++.h>
using namespace std;

int n;
string goodNum;

//백트래킹
void dfs(int cnt, char num) {
    if(cnt - 1 == n) {
        cout << goodNum << "\n";
        exit(0); //처음에 나오는 숫자가 가장 작은 수 / 0이면 정상 종료. 0이아닌수 사용 x
        //바로 종료
        
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