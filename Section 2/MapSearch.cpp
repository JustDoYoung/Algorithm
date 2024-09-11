#include "bits/stdc++.h"

using namespace std;

const int N = 3;
int arr[N][N];
bool visited[N][N];

int dirY[] = {-1, 0, 1, 0};
int dirX[] = {0, 1, 0, -1};

void go(int y, int x)
{
    visited[y][x] = 1;
    cout << "[ " << y << ", " << x << " ]" << "\n";

    for (int i = 0; i < 4; i++)
    {
        int dy = y + dirY[i];
        int dx = x + dirX[i];

        if (dy < 0 || dx < 0 || dy >= N || dx >= N)
            continue;
        if (arr[dy][dx] == 0)
            continue;
        if (visited[dy][dx])
            continue;

        go(dy, dx);
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    arr[0][0] = 1;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[j][i] == 0)
                continue;
            if (visited[j][i])
                continue;

            go(j, i);
        }
    }
}