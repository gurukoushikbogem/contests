
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    string s;
    cin >> s;

    vector<pair<int, int>> vt(26);

    for (int i = 0; i < 26; i++)
    {
        vt[i].first = i;
    }

    for (char k : s)
    {
        int index = k - 'a';
        vt[index].second = vt[index].second + 1;
    }

    sort(vt.begin(), vt.end(), comp);

    string ans = "";

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < vt[i].second; j++)
        {
            ans += char(vt[i].first + 'a');
        }
    }
    cout << ans << endl;
}