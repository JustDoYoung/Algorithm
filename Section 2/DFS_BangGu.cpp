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