#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1'000'000;
const long long MOD = 1'000'000'007LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<int> freq(MAXA + 1, 0);
    vector<long long> tau(MAXA + 1, 0);

    int mx = 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        ++freq[A[i]];
        mx = max(mx, A[i]);
    }

    for (int d = 1; d <= mx; ++d)
        for (int m = d; m <= mx; m += d)
            ++tau[m];

    for (int d = 1; d <= mx; ++d)
        for (int m = 2 * d; m <= mx; m += d)
            freq[d] += freq[m];

    long long sumTau = 0;
    for (int x : A)
    {
        sumTau += tau[x];
        if (sumTau >= MOD)
            sumTau -= MOD;
    }

    vector<long long> f(mx + 1, 0);
    for (int g = mx; g >= 1; --g)
    {
        long long c = freq[g];
        long long gcnt = c * (c - 1) / 2; 
        long long sub = 0;
        for (int m = 2 * g; m <= mx; m += g)
            sub += f[m];
        f[g] = gcnt - sub; 
    }

    long long sumG = 0;
    for (int g = 1; g <= mx; ++g)
    {
        if (f[g] == 0)
            continue;
        long long add = (f[g] % MOD) * (tau[g] % MOD) % MOD;
        sumG += add;
        if (sumG >= MOD)
            sumG -= MOD;
    }

    long long ans = (((long long)(N - 1) * (sumTau % MOD)) % MOD - (2LL * sumG) % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
