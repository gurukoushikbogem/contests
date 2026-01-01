#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define endl "\n"
#define mod ((int)(1e9) + 7ll)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define si set<int>
#define pi pair<int,int>
#define mi map<int, int>
#define miv map<int,vector<int>>
using namespace std;

void solve(){
    int ones = 0, zeros = 0, c = 0, k = 0, p = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n *(n + 1);
    ans /= 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ones++;
        else
            zeros++;
        if (ones - zeros == 0)
        {
            k++;
        }
        if (mp.find(ones - zeros) != mp.end())
        {
            p += (mp[ones - zeros]);
            mp[ones - zeros]++;
        }
        else
        {
            mp[ones - zeros]++;
        }
    }
    cout << ans+k+p << endl;
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; cin>>t;
    while(t--){
        solve();
    }
}

