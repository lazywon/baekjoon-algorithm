#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int cnt = 0;
    cin >> n >> m;

    deque<int> dq;

    for(int i=1;i<=n;i++) {
        dq.push_back(i);
    }

    for(int i=0;i<m;i++) {
        int num, index;
        cin >> num;

        for(int i=0;i<dq.size();i++) {
            if(dq[i] == num) {
                index = i;
                break;
            }
        }

        if(index < dq.size() - index) {
            while(1) {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else {
            while(1) {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
    }
   
    cout << cnt << "\n";


    return 0;
}