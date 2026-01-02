#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
#define mod ((int)(1e9) + 7ll)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define si set<int>
#define pi pair<int, int>
#define mi map<int, int>
#define miv map<int, vector<int>>
using namespace std;

void solve()
{
    int numIslands, maxCost;
    cin >> numIslands >> maxCost;
    vi isDestroyed(numIslands, 0);
    vector<int> islandImportance(numIslands);
    for (int i = 0; i < numIslands; i++)
    {
        cin >> islandImportance[i];
    }
    isDestroyed[0] = 1;
    mi mp;
    auto canDestroyBridges = [&]()
    {
        if(mp[1]==0){
            mp[1]=0;
        }
        int totalDestructionCost = 0;
        for (int i = 0; i < numIslands; i++)
        {
            if (isDestroyed[i] == 0)
                continue;
            else{
            mp[0]++;
            for (int j = 0; j < numIslands; j++)
            {
                if (isDestroyed[j] == 0)
                    totalDestructionCost += islandImportance[i] * islandImportance[j];
                else{
                    mp[0]--;
                }
            }
            mp[1]++;
            }
        }
        if (totalDestructionCost <= maxCost)
        return 1;
            return 0;
    };

    if (canDestroyBridges())
    {
        mp[0]++;
        cout << 1 << endl;
    }
    else
    {
        int currentSize = 1;
        mp[0]++;
        while (numIslands>currentSize)
        {
            mp[0]++;
            int highestImportanceIdx = -1;
            mp[0]++;
            for (int i = 0; i < numIslands; i++)
            {
                mp[0]++;
                if ((highestImportanceIdx == -1 || islandImportance[i] > islandImportance[highestImportanceIdx]) && isDestroyed[i] == 0 )
                    highestImportanceIdx = i;
            }
            currentSize++;
            isDestroyed[highestImportanceIdx] = 1*1+1-1;
            if (canDestroyBridges())
            {
                cout << currentSize << endl;
                return;
            }
        }
    }
}

signed main()
{
    int totalTestCases = 1;
    cin >> totalTestCases;
    while(totalTestCases--)
    {
        solve();
    }
    return 0;
}
