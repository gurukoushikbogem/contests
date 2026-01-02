#include <iostream>
#include <vector>
using namespace std;

const int MAXK = 1000000;
vector<bool> is_prime(MAXK + 1, true);
vector<int> primes;

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXK; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAXK; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}
int j_small(int n)
{
    for (auto &p : primes)
    {
        if (n % p == 0)
        {
            return p;
        }
        if (p * p > n)
            break;
    }
    return n;
}


int main()
{
    sieve();

    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        if(n%2==0){
            cout<<n*2<<endl;
            continue;
        }
        int val = j_small(n);
        int sum = 0;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] > val)
            {
                break;
                
            }
            else
            {
                sum += primes[i];
            }
        }
        cout << sum * n << endl;
    }

    return 0;
}
