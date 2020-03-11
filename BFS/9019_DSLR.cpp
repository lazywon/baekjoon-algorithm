/* #include <bits/stdc++.h>
using namespace std;

int commandD(int n) {
    int res = 2 * n;
    if(res > 9999) res = res % 10000;
    return res;
}

int commandS(int n) {
    if(n == 0) return 9999;
    return n - 1;
}

int commandL(int n) {
    vector<int> d;
    int tmp = n;
    if(n >= 1000) {
        d.push_back(tmp / 1000);
        tmp %= 1000;
        d.push_back(tmp / 100);
        tmp %= 100;
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else if(n >= 100) {
        d.push_back(tmp / 100);
        tmp %= 100;
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else if(n >= 10) {
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else {
        d.push_back(tmp);
    }

    vector<int> v(d.size());
    
    for(int i=0;i<v.size();i++) {
        v[i] = d[i];
    }

    for(int i=0;i<d.size();i++) {
        if(i == 0) d[d.size()-1] = v[i];
        else d[i-1] = v[i];
    }

    int res;
    if(d.size() == 1) {
        res = d[0];
    } else if(d.size() == 2) {
        res = (d[0] * 10 + d[1]);
    } else if(d.size() == 3) {
        res = (d[0] * 10 + d[1]) * 10 + d[2];
    } else {
        res = ((d[0] * 10 + d[1]) * 10 + d[2]) * 10 + d[3];
    }

    return res;
}

int commandR(int n) {
    vector<int> d;
    int tmp = n;
    if(n >= 1000) {
        d.push_back(tmp / 1000);
        tmp %= 1000;
        d.push_back(tmp / 100);
        tmp %= 100;
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else if(n >= 100) {
        d.push_back(tmp / 100);
        tmp %= 100;
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else if(n >= 10) {
        d.push_back(tmp / 10);
        tmp %= 10;
        d.push_back(tmp);
    } else {
        d.push_back(tmp);
    }

    vector<int> v(d.size());
    
    for(int i=0;i<v.size();i++) {
        v[i] = d[i];
    }

    for(int i=0;i<d.size();i++) {
        if(i == d.size()-1) d[0] = v[i];
        else d[i+1] = v[i];
    }

    int res;
    if(d.size() == 1) {
        res = d[0];
    } else if(d.size() == 2) {
        res = (d[0] * 10 + d[1]);
    } else if(d.size() == 3) {
        res = (d[0] * 10 + d[1]) * 10 + d[2];
    } else {
        res = ((d[0] * 10 + d[1]) * 10 + d[2]) * 10 + d[3];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for(int T=1;T<=tc;T++) {
        int a, b;
        cin >> a >> b;

        int ret = a;
        while(1) {
            if(ret == b) break;

        }
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int A, B;
bool visit[MAX];

string bfs(int a) {
    queue<pair<int, string> > q;
    q.push(make_pair(a, ""));
    visit[a] = true;

    while(!q.empty()) {
        int x = q.front().first; //현재 숫자
        string s = q.front().second; // 명령어
        q.pop();

        if(x == B) return s; // A=B가되면 정답

        // D
        int nx = x * 2;
        if(nx > 9999) nx = nx % 10000;
        if(visit[nx] == false) {
            visit[nx] = true;
            q.push(make_pair(nx, s + "D"));
        } 

        // S
        nx = x - 1;
        if(nx < 0) nx = 9999;
        if(visit[nx] == false) {
            visit[nx] = true;
            q.push(make_pair(nx, s + "S"));
        }

        //L
        nx = (x % 1000) * 10 + (x / 1000);
        if(visit[nx] == false) {
            visit[nx] = true;
            q.push(make_pair(nx, s + "L"));
        }

        //R
        nx = (x % 10) * 1000 + (x / 10);
        if(visit[nx] == false) {
            visit[nx] = true;
            q.push(make_pair(nx, s + "R"));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for(int T=1;T<=tc;T++) {
        memset(visit, false, sizeof(visit));

        cin >> A >> B;

        string ret = bfs(A);
        cout << ret << "\n";
    }

    return 0;
}