#include "bits/stdc++.h"

using namespace std;

const int v = 10;
vector<int> adj[v];
bool visited[v];

void go(int from)
{
    visited[from] = 1;
    cout << from << ' ';

    for (int j : adj[from])
    {
        if (visited[j])
            continue;

        go(j);
    }
}
int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);

    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[4].push_back(3);

    for (int i = 0; i < v; i++)
    {
        if (adj[i].size() == 0 || visited[i])
            continue;

        go(i);
    }
}