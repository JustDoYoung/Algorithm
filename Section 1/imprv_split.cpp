#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> v;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != string::npos)
    {
        v.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    v.push_back(input.substr(start, end - start));

    return v;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s = "이더리움은 세상에서 가장 훌륭한 암호화폐입니다.";
    string d = " ";

    vector<string> v = split(s, d);

    for (string i : v)
        cout << i << '\n';

    return 0;
}