#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //priority_queue<int, vector<int>, greater<int> > pq;
    //priority_queue<int> 로 선언시 최대힙, 위와같이 선언시 최소힙

    priority_queue<int> pq;

    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;

        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n"; //가장 작은 값
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}

/*
Q. 힙에서 할 수 있는건 어차피 균형 이진 트리에서도 할 수 있지 않나요? 
그러면 균형 이진 트리가 더 제공해주는 기능이 많은데 힙을 쓸 이유가 있나요?

A. 힙에서 할 수 있는걸 균형 이진 트리에서 할 수 있는 것이 맞고, 자가 균형 트리라는 가정하에 시간복잡도가 O(lg N)O(lgN)으로 동일한 것도 맞습니다. 
그러나 힙은 균형 이진 트리보다 수행 속도도 빠르고, 구현도 쉽고, 공간도 적게 차지하기에 최소 혹은 최댓값의 확인/삭제만 필요할 떄에는 힙을 쓰는 것이 더 좋습니다.
*/

// STL set, map, priority_queue 꼭 익혀두자!!!!!!!