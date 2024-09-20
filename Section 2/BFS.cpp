#include "bits/stdc++.h"

using namespace std;

const int N = 100;
vector<int> v[N];
int visited[N];
int lv = 1;

void BFS(int u)
{
    visited[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size())
    {
        int now = q.front();
        q.pop();

        cout << "현재 노드는 >> " << now << '\n';

        cout << "연결된 노드는 >> ";
        for (int next : v[now])
        {
            if (visited[next])
                continue;

            cout << next << ' ';

            visited[next] = visited[now] + 1;
            q.push(next);
        }

        cout << '\n';
    }
}

int main()
{
    int nodes[] = {10, 12, 14, 16, 18, 20, 22, 24};

    v[10].push_back(12);
    v[10].push_back(14);
    v[10].push_back(16);

    v[12].push_back(18);
    v[12].push_back(20);

    v[20].push_back(22);
    v[20].push_back(24);

    BFS(10);

    cout << "10번 노드로부터 각 노드들의 최단거리는 " << '\n';

    for (int node : nodes)
    {
        cout << node << " : " << visited[node] << '\n';
    }
}