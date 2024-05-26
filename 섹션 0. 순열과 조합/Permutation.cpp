#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char arr[] = {'a', 'b', 'c'};
    vector<char> v;

    for (int i = 0; i <= 2; i++)
        v.push_back(arr[i]);

    do
    {
        for (char i : v)
            cout << i << ' ';
        cout << '\n';

    } while (next_permutation(v.begin(), v.end()));
}