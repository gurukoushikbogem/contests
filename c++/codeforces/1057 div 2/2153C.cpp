/* Author: S. Nithish Kumar :: nithish654 :: */
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int N = 2e5 + 10, M = 1e9 + 7, mod = 998244353, INF = 1e18;

bool test_cases = true;
void light()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    map<int, int> mp;
    for (int x : a)
        mp[x]++;

    int ans = 0, f = 0;
    vector<int> b;
    for (auto [k, v] : mp)
    {
        if (v & 1)
            b.push_back(k);
        v -= (v & 1);
        f += v;
        ans += v * k;
    }

    reverse(b.begin(), b.end());

    for (int i = 0; ans > 0 and i < b.size(); i++)
    {
        if (b[i] < ans + (i + 1 < b.size() ? b[i + 1] : 0))
        {
            ans += b[i] + (i + 1 < b.size() ? b[i + 1] : 0);
            cout << ans << '\n';
            return;
        }
    }

    if (f <= 2)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if (test_cases)
        cin >> t;
    while (t--)
        light();
    return 0;
}