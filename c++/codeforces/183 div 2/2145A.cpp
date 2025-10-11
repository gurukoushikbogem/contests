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
        int rem = n % 3;
        if (rem != 0)
            rem = 3 - rem;
        cout << rem << endl;
    }
}
