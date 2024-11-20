#include <bits/stdc++.h>

using namespace std;

int N;
char arr[65][65];

string quad(int y, int x, int w)
{
    string ret = "";
    stack<tuple<int, int, int, string>> s;
    s.push({y, x, w, ""});

    while (!s.empty())
    {
        auto [cy, cx, w, close] = s.top();
        char now = arr[cy][cx];
        s.pop();

        bool same = true;
        for (int j = cy; j < cy + w; j++)
        {
            for (int i = cx; i < cx + w; i++)
            {
                if (arr[j][i] != now)
                {
                    ret += "(";
                    s.push({cy + w / 2, cx + w / 2, w / 2, close + ")"});
                    s.push({cy + w / 2, cx, w / 2, ""});
                    s.push({cy, cx + w / 2, w / 2, ""});
                    s.push({cy, cx, w / 2, ""});
                    same = false;
                    break;
                }
            }
            if (!same)
                break;
        }

        if (same)
        {
            ret += now + close;
        }
    }

    return ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            arr[i][j] = input[j];
        }
    }

    cout << quad(0, 0, N) << '\n';

    return 0;
}
