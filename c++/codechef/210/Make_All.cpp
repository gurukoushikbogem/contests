#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;

long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

void solution()
{
    int k;
    cin >> k;

    int n = 100000;
    vector<int> primes = sieve(n);

    set<long long> s;

    for (int prime : primes)
    {
        long long val = 1;
        for (int exp = 0; exp <= 20; exp++)
        {
            if (exp > 0)
            {
                val = (val * prime);
                if (val > 1e6)
                    break;
            }
            s.insert(val);
        }
    }

    vector<long long> v(s.begin(), s.end());

    for (int i = 0; i < 20 && i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    solution();
    return 0;
}