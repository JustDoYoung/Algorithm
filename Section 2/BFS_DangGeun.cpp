#include "bits/stdc++.h"

using namespace std;

int N, M;
int arr[100][100];
int visited[100][100];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size())
    {
        int nowY, nowX;
        tie(nowY, nowX) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (arr[nextY][nextX] == 0)
                continue;

            q.push({nextY, nextX});
            visited[nextY][nextX] = visited[nowY][nowX] + 1;
        }
    }
}
int main()
{
    int a, b, c, d;
    cin >> N >> M;
    cin >> a >> b >> c >> d;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> arr[j][i];
        }
    }

    bfs(a, b);

    cout << "방문한 정점들의 가중치는 " << '\n';

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cout << visited[j][i] << ' ';
        }
        cout << '\n';
    }

    cout << "[ " << c << ", " << d << " ] " << "목적지까지 최단거리는 " << visited[c][d];
}