#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 3;
int arr[] = {1, 2, 3, 4, 5};

void print(vector<int> v)
{
    for (int i : v)
        cout << i << ' ';
    cout << '\n';
}

void Combination(int s, vector<int> v)
{
    if (v.size() == k)
    {
        print(v);
        return;
    }

    for (int i = s; i < n; i++)
    {
        v.push_back(i);
        Combination(i + 1, v);
        v.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    Combination(0, v);

    return 0;
}