#include "bits/stdc++.h"

using namespace std;

vector<int> adj[1004];
bool visited[1004];

void PostOrder(int node)
{
    if (visited[node])
        return;

    for (int i : adj[node])
        PostOrder(i);

    visited[node] = true;
    cout << node << ' ';
}

void PreOrder(int node)
{
    if (visited[node])
        return;

    cout << node << ' ';
    visited[node] = true;

    for (int i : adj[node])
        PreOrder(i);
}

void InOrder(int node)
{
    if (visited[node])
        return;

    for (int i = 0; i < adj[node].size(); i++)
    {
        InOrder(adj[node][i]);
        if (visited[adj[node][i]] == false)
        {
            cout << adj[node][i] << ' ';
            visited[adj[node][i]] = true;
        }

        if (i == 0)
        {
            cout << node << ' ';
            visited[node] = true;
        }
    }
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;

    cout << "-----Post Order(후위순회)-----\n";
    PostOrder(root); // 4 5 2 3 1
    cout << '\n';

    memset(visited, 0, sizeof(visited));

    cout << "-----Pre Order(전위순회)-----\n";
    PreOrder(root); // 1 2 4 5 3
    cout << '\n';

    memset(visited, 0, sizeof(visited));

    cout << "-----In Order(중위순회)-----\n";
    InOrder(root); // 4 2 5 1 3
    cout << '\n';
}