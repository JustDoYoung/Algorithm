#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int num = 666;

    while (true)
    {
        string num_s = to_string(num);
        if (num_s.find("666") != string::npos)
            N--;
        if (N == 0)
            break;
        num++;
    }

    cout << num << '\n';

    return 0;
}
