#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> factors;
    for (long long i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            factors.push_back(i);
            if (i != k / i)
                factors.push_back(k / i);
        }
    }
    sort(factors.begin(), factors.end());
    unordered_map<long long, int> factorIndex;
    for (int i = 0; i < factors.size(); i++)
    {
        factorIndex[factors[i]] = i;
    }

    vector<long long> dp(factors.size(), 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<long long> new_dp = dp;
        for (int j = factors.size() - 1; j >= 0; j--)
        {
            if (factors[j] % a[i] == 0)
            {
                long long target = factors[j] / a[i];
                if (factorIndex.count(target))
                {
                    new_dp[j] = (new_dp[j] + dp[factorIndex[target]]) % MOD;
                }
            }
        }
        dp = new_dp;
    }

    cout << dp[factors.size() - 1] % MOD << "\n";
    return 0;
}
