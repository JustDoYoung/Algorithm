#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n = 5, k = 3;
    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                cout << i << ' ';
                cout << j << ' ';
                cout << k << '\n';
            }
        }
    }

    return 0;
}