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
        string s, tt = "";
        cin >> s;
        for (auto i : s)
        {
            if (i == '0')
            {
                tt += "1";
            }
            else
            {
                tt += "0";
            }
        }
        cout << tt << endl;
    }
}
