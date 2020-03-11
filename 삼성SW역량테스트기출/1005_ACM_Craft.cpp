/*
    위상정렬 - 그래프를 정렬하는 것
    조건 : 방향성이 있고, 사이클이 없어야 함

    정점에 대해 최대 시간이 건물의 최소 시간이 된다!!
    ->동시에 건물을 지을 수 있어도 동시에 짓기 시작한 건물이 모두 완성되어야 
      다음 건물을 지을 수 있기 때문
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
        indegree.resize(n + 1); //간선의 개수
        p.resize(n + 1);

        for(int i=1;i<=n;i++) {
            cin >> times[i]; //빌딩 짓는데 걸리는 시간
        }
        for(int i=0;i<k;i++) { //규칙수
            int u, v; 
            cin >> u >> v;
            p[u].push_back(v);
            indegree[v]++;
        }

        cin >> w; // w번째 건물까지

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
                int next = p[now][i]; //현재와 이어져있는 간선
                if(--indegree[next] == 0) { //간선수가 0이되면 다음 단계. 건물 짓기로
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