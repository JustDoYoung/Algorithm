## 1. DFS
> 그래프나 맵을 탐색할 때 사용되는 알고리즘입니다. 특정 노드에서 시작해 한 경로를 끝까지 탐색합니다. 연결된 노드들을 재귀적으로 탐색하고 한 번 탐색한 노드는 다시 탐색하지 않습니다.

## 1.1 구현 방법
> 방문 체크를 구현하는 코드의 위치에 따라 2가지 방법으로 나뉠 수 있습니다.
1. 연결된 노드를 반복문 안에서 방문여부를 체크
2. 연결된 모든 노드를 일단 재귀함수로 호출하고 함수 시작부분에 방문여부 체크

## 2. DFS 구현
```c++
#include "bits/stdc++.h"

using namespace std;

const int n = 6;
vector<int> v[n];
int visited[n];

void dfs(int n)
{
    visited[n] = 1;
    cout << n << '\n';

    for (int i : v[n])
    {
        if (visited[i])
            continue;

        dfs(i);
    }

    cout << "정점 " << n << "의 재귀 종료" << '\n';
}
int main()
{
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(4);
    v[2].push_back(5);
    v[4].push_back(2);

    dfs(1);
}
```   
- 출력   
1   
2   
4   
정점 4의 재귀 종료   
5   
정점 5의 재귀 종료   
정점 2의 재귀 종료   
3   
정점 3의 재귀 종료   
정점 1의 재귀 종료   

## 3. 방구쟁이 종화 예제
```c++
#include "bits/stdc++.h"

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

const int n = 5;
int arr[n][n];
bool visited[n][n];
int cnt = 0;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int deltaY = y + dy[i];
        int deltaX = x + dx[i];

        if (deltaY < 0 || deltaY >= n || deltaX < 0 || deltaX >= n)
            continue;
        if (visited[deltaY][deltaX])
            continue;
        if (arr[deltaY][deltaX] == 0)
            continue;

        dfs(deltaY, deltaX);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (visited[j][i])
                continue;
            if (arr[j][i] == 0)
                continue;

            dfs(j, i);

            cout << "[ " << j << ", " << i << " ] " << "이러다... 다 죽어...!" << endl;
            cnt++;
        }
    }

    cout << cnt << endl;
}
```
#### 출력
[ 0, 0 ] 이러다... 다 죽어...!   
[ 0, 2 ] 이러다... 다 죽어...!   
[ 0, 4 ] 이러다... 다 죽어...!   
[ 4, 1 ] 이러다... 다 죽어...!   
4

- 이 문제는 맵과 관련된 문제로 연결된 컴포넌트의 개수를 찾는 것이 핵심
- DFS를 통해 특정 노드와 연결된 노드들을 더 이상 연결되지 않은 노드까지 재귀적으로 탐색하고 cnt를 1씩 증가.