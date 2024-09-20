## 1. BFS
> 그래프나 맵을 탐색할 때 사용되는 알고리즘입니다.   
특정 노드에서 시작해 같은 레벨에 있고 연결된 노드들을 탐색하고 재방문을 하지 않습니다.   
같은 가중치를 가진 그래프의 최단거리 알고리즘으로 사용됩니다.

## 1.1 구현 방법
1. 시작 노드인 u를 방문처리하고 Queue에 푸시.
2. Queue의 사이즈가 0이 될 때까지 반복문 실행.
3. 반복문 안에서 현재 노드와 연결된 노드들을 Queue에 푸시.
4. 현재 노드가 방문처리가 되지 않았으면 방문처리.

- 최단거리 알고리즘으로 사용될 경우 단순히 방문처리만 하는 것이 아니라 부모 노드에서 가중치를 더 해주면서 구현해야 함.

## 2. BFS 구현
```c++
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
```   

## 3. 당근마켓 예제
```c++
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
```
#### 출력
방문한 정점들의 가중치는   
1 0 5 0 9   
2 3 4 0 8   
0 0 5 6 7  
0 0 6 7 8  
0 0 7 8 9  
[ 4, 4 ] 목적지까지 최단거리는 9  

## 4. DFS vs BFS
- DFS는 BFS에 비해 메모리 사용량이 적음.  
(DFS는 깊이 우선 탐색이기 때문에 현재 경로의 노드만 스택에 저장하기 때문에. 반면 BFS는 현재 레벨의 모든 노드를 큐에 저장해야하기 때문에 메모리 사용량이 많음.)
- DFS가 절단점을 찾기에 적합.
- 완전탐색의 경우 DFS를 많이 사용.
- 가중치가 같은 그래프 탐색에 BFS를 사용.