#include "bits/stdc++.h"

using namespace std;

const int v = 10;
bool arr[v][v], visited[v];

void go(int from)
{
    visited[from] = 1;
    cout << from << ' ';

    for (int i = 0; i < v; i++)
    {
        if (arr[from][i] == 0)
            continue;
        if (visited[i] == 1)
            continue;

        go(i);
    }
}

int main()
{
    arr[1][2] = arr[1][3] = arr[3][4] = 1;
    arr[2][1] = arr[3][1] = arr[4][3] = 1;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (!arr[i][j] || visited[j])
                continue;

            go(i);
        }
    }

    // 출력 : 1 2 3 4
}