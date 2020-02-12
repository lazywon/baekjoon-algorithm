//다시풀기....

#include <bits/stdc++.h>
using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> positive;
//(데이터타입, 컨테이너타입, 정렬기준(오름차순))
priority_queue<int> negative; //디폴트: 내림차순(less)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int one = 0, zero = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 1)
            one++;
        else if (num > 0)
            positive.push(num);
        else if (num == 0)
            zero++;
        else
            negative.push(num);
    }

    //짝이 없는 양수를 위해 1을 곱해준다
    if (positive.size() % 2)
        positive.push(1);

    //0이 존재한다면 짝이 없는 음수에 0을 곱해준다
    //0이 존재하지 않는다면 짝이 없는 음수에 1을 곱해준다
    if (negative.size() % 2)
        zero == 0 ? negative.push(1) : negative.push(0);

    int sum = 0;

    //양수들을 합해주고
    while(!positive.empty())
    {
        int num1 = positive.top();
        positive.pop();
        int num2 = positive.top();
        positive.pop();
        sum += (num1*num2);
    }

    //음수들을 합해준다
    while(!negative.empty())
    {
        int num1 = negative.top();
        negative.pop();
        int num2 = negative.top();
        negative.pop();

        sum += (num1*num2);
    }

    //1들은 그냥 더해준다
    cout << sum + one << "\n";
    
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>  n;
    int arr[n];

    vector<int> posi;
    vector<int> nega;
    int zero = -1, one = 0;

    for(int i=0;i<n;i++) {
        cin >> arr[i];

        if(arr[i] == 1) {
            one = 1;
        }
        
    }
    if(n == 1) {
        cout << arr[0];
        return 0;
    }

    sort(arr, arr+n);

    for(int i=0;i<n;i++) {
        if(arr[i] <= 0) {
            nega.push_back(arr[i]);
        }
        else if(arr[i] > 1) {
            posi.push_back(arr[i]);
        }
    }

    long long ret = 0;
    int nega_size = nega.size();
    int posi_size = posi.size();

    if(nega_size % 2 == 0){
        for(int i=0;i<nega_size;i+=2) {
            ret += (nega[i] * nega[i+1]);
        }
    } else {
        for(int i=0;i<nega_size-1;i+=2) {
            ret += (nega[i] * nega[i+1]);
        }
        ret += nega[nega_size - 1];
    }

    if(posi_size % 2 == 0) {
        for(int i=posi_size-1;i>=0;i-=2) {
            ret += (posi[i] * posi[i-1]);
        }
    } else {
        for(int i=posi_size-1;i>=1;i-=2) {
            ret += (posi[i] * posi[i-1]);
        }
        ret += posi[0];
    }

    ret += one;

    cout << ret << "\n";

    return 0;
}
*/