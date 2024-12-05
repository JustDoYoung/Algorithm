#include <bits/stdc++.h>

using namespace std;

int N;
int nums[1000004];
int ans[1000004];
stack<int> st;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    fill(&ans[0], &ans[N], -1);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];

        while (!st.empty() && nums[st.top()] < nums[i])
        {
            ans[st.top()] = nums[i];
            st.pop();
        }

        st.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}