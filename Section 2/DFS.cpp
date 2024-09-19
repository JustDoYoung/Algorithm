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