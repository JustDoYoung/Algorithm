#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> v;
    size_t pos = 0;
    string temp = "";

    while ((pos = input.find(delimiter)) != string::npos)
    {
        temp = input.substr(0, pos);
        v.push_back(temp);
        input.erase(0, pos + delimiter.length());
    }

    v.push_back(input);

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