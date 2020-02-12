#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //priority_queue<int, vector<int>, greater<int> > pq;
    //priority_queue<int> �� ����� �ִ���, ���Ͱ��� ����� �ּ���

    priority_queue<int> pq;

    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;

        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n"; //���� ���� ��
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}

/*
Q. ������ �� �� �ִ°� ������ ���� ���� Ʈ�������� �� �� ���� �ʳ���? 
�׷��� ���� ���� Ʈ���� �� �������ִ� ����� ������ ���� �� ������ �ֳ���?

A. ������ �� �� �ִ°� ���� ���� Ʈ������ �� �� �ִ� ���� �°�, �ڰ� ���� Ʈ����� �����Ͽ� �ð����⵵�� O(lg N)O(lgN)���� ������ �͵� �½��ϴ�. 
�׷��� ���� ���� ���� Ʈ������ ���� �ӵ��� ������, ������ ����, ������ ���� �����ϱ⿡ �ּ� Ȥ�� �ִ��� Ȯ��/������ �ʿ��� ������ ���� ���� ���� �� �����ϴ�.
*/

// STL set, map, priority_queue �� ��������!!!!!!!