//Union Find(=Disjoint Set) 사용 **
//다시풀것..
//(map-log n) / set / (hash-1) map?

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000 + 1

int F;
int arr[MAX];

int findRoot(int num) {
    if(arr[num] < 0)
        return num;

    int root = findRoot(arr[num]);
    arr[num] = root;
    return root;
}

void merge(int aParent, int bParent) {
    if(abs(aParent) >= abs(aParent)) {
        arr[aParent] += arr[bParent];
        arr[bParent] = aParent;
    } else
    {
        arr[bParent] += arr[aParent];
        arr[aParent] = bParent;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    for(int t=1;t<=tc;t++) {
        cin >> F;

        memset(arr, -1, sizeof(arr));

        map<string, int> name;
        int idx = 1;

        for(int i=0;i<F;i++) {
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;

            if(name.count(tmp1) == 0)
                name[tmp1] = idx++;
            if(name.count(tmp2) == 0) 
                name[tmp2] = idx++;

            int tmp1Root = findRoot(name[tmp1]);
            int tmp2Root = findRoot(name[tmp2]);

            if(tmp1Root == tmp2Root)
                cout << abs(arr[tmp1Root]) << "\n";
            else
            {
                merge(tmp1Root, tmp2Root);
                cout << abs(arr[tmp1Root]) << "\n";
            }
            
        }
    }
        

    return 0;
}