#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2)
                c1++;
            else
                c2++;
        }
        int ans = 0, f = 0, prev = 0;
        while (c1 > 0 || c2 > 0)
        {
            int k = prev % 2;
            if (k == 0)
            {
                if (c1 > 0)
                {
                    c1--;
                    prev = 1;
                    ans++;
                }
                else
                {
                    c2--;
                    prev = 0;
                }
            }
            else
            {
                if (k == 1 && c2 > 0)
                {
                    c2--;
                    prev = 1;
                    ans++;
                }
                else
                {
                    c1--;
                    prev = 0;
                }
            }
        }
        cout << ans << endl;
    }
}
