#include <bits/stdc++.h>

using namespace std;

// 재귀를 이용한 순열
int arr[] = {1, 2, 3};
int n = 3, r = 3;

void print()
{
    for (int i = 0; i < r; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void makePermutation(int n, int r, int depth)
{
    // 기저 사례
    if (r == depth)
    {
        print();
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(arr[i], arr[depth]);
        makePermutation(n, r, depth + 1);
        swap(arr[i], arr[depth]);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    makePermutation(n, r, 0);
}
