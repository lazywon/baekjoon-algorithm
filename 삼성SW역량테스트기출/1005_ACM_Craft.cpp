/*
    �������� - �׷����� �����ϴ� ��
    ���� : ���⼺�� �ְ�, ����Ŭ�� ����� ��

    ������ ���� �ִ� �ð��� �ǹ��� �ּ� �ð��� �ȴ�!!
    ->���ÿ� �ǹ��� ���� �� �־ ���ÿ� ���� ������ �ǹ��� ��� �ϼ��Ǿ�� 
      ���� �ǹ��� ���� �� �ֱ� ����
*/
#include <bits/stdc++.h>
using namespace std;

int tc, n, k, w;
vector<vector<int> > p;
vector<int> dist, times, indegree;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for(int T=1;T<=tc;T++) {
        dist.clear(); 
        times.clear();
        indegree.clear();
        p.clear();

        cin >> n >> k;

        dist.resize(n + 1);
        times.resize(n + 1);
        indegree.resize(n + 1); //������ ����
        p.resize(n + 1);

        for(int i=1;i<=n;i++) {
            cin >> times[i]; //���� ���µ� �ɸ��� �ð�
        }
        for(int i=0;i<k;i++) { //��Ģ��
            int u, v; 
            cin >> u >> v;
            p[u].push_back(v);
            indegree[v]++;
        }

        cin >> w; // w��° �ǹ�����

        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dist[i] = times[i];
            }
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            if(now == w) break;

            for(int i=0;i<p[now].size();i++) {
                int next = p[now][i]; //����� �̾����ִ� ����
                if(--indegree[next] == 0) { //�������� 0�̵Ǹ� ���� �ܰ�. �ǹ� �����
                    q.push(next);
                }
                if(dist[next] < dist[now] + times[next]) {
                    dist[next] = dist[now] + times[next];
                }
            }
        }
        cout << dist[w] << "\n";

    }

    return 0;
}