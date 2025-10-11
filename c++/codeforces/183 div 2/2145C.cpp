#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string v;
        cin >> v;
        int c3 = 0, c4 = 0;
        vector<int> v1, v2;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 'a')
                c3++;
            else
                c4++;
            if (c3 == c4)
            {
                v1.push_back(i);
            }
        }

        c3 = 0, c4 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == 'a')
                c3++;
            else
                c4++;
            if (c3 == c4)
            {
                v2.push_back(i);
            }
        }

        reverse(v2.begin(), v2.end());

        int ans = INT_MAX;

        if (v1.size() > 0)
        {
            ans = min(ans, n - v1.back() - 1);
        }
        if (v2.size() > 0)
        {
            ans = min(ans, v2[0]);
        }

        map<int, vector<int>> mp1;
        int c = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == 'a')
                c++;
            else
                c--;
            mp1[c].push_back(i);
        }
        c = 0;
        for (auto &it : mp1)
        {
            reverse(it.second.begin(), it.second.end());
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 'a')
                c++;
            else
                c--;
            if (mp1.find(c * (-1)) != mp1.end())
            {
                auto &tt = mp1[c * (-1)];
                auto it = upper_bound(tt.begin(), tt.end(), i);
                if (it != tt.end())
                {
                    ans = min(ans, *it - i - 1);
                }
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}