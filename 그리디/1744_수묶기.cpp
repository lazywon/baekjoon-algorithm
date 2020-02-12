//�ٽ�Ǯ��....

#include <bits/stdc++.h>
using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> positive;
//(������Ÿ��, �����̳�Ÿ��, ���ı���(��������))
priority_queue<int> negative; //����Ʈ: ��������(less)

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

    //¦�� ���� ����� ���� 1�� �����ش�
    if (positive.size() % 2)
        positive.push(1);

    //0�� �����Ѵٸ� ¦�� ���� ������ 0�� �����ش�
    //0�� �������� �ʴ´ٸ� ¦�� ���� ������ 1�� �����ش�
    if (negative.size() % 2)
        zero == 0 ? negative.push(1) : negative.push(0);

    int sum = 0;

    //������� �����ְ�
    while(!positive.empty())
    {
        int num1 = positive.top();
        positive.pop();
        int num2 = positive.top();
        positive.pop();
        sum += (num1*num2);
    }

    //�������� �����ش�
    while(!negative.empty())
    {
        int num1 = negative.top();
        negative.pop();
        int num2 = negative.top();
        negative.pop();

        sum += (num1*num2);
    }

    //1���� �׳� �����ش�
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