#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool canAchieveCapacity(int N, long long X, const vector<int> &A, const vector<int> &P, const vector<int> &B, const vector<int> &Q, long long W)
{
    long long totalCost = 0;

    for (int i = 0; i < N; ++i)
    {
        long long costSi = LLONG_MAX, costTi = LLONG_MAX;

        if (A[i] > 0)
        {
            long long neededSi = (W + A[i] - 1) / A[i]; 
            costSi = neededSi * P[i];
        }

        if (B[i] > 0)
        {
            long long neededTi = (W + B[i] - 1) / B[i]; 
            costTi = neededTi * Q[i];
        }

        totalCost += min(costSi, costTi);

        if (totalCost > X)
            return false;
    }

    return totalCost <= X;
}

long long maximizeProductionCapacity(int N, long long X, const vector<int> &A, const vector<int> &P, const vector<int> &B, const vector<int> &Q)
{
    long long low = 0, high = 1e9, answer = 0;
    
    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (canAchieveCapacity(N, X, A, P, B, Q, mid))
        {
            answer = mid;  
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    return answer;
}

int main()
{
    int N;
    long long X;
    cin >> N >> X;

    vector<int> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    long long result = maximizeProductionCapacity(N, X, A, P, B, Q);

    cout << result << endl;

    return 0;
}
