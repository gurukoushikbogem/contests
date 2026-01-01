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
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int kk = *max_element(v.begin(), v.end());
    map<int, vi> mp;
    unordered_map<int, int> mp1;
    for (int i = 0; i < n;i++){
        int k = v[i];
        for (int j = 31; j >= 0;j--){
            if((v[i]>>j)&1){
                mp[j].push_back(k);
            }
        }
        mp1[v[i]]++;
    }
    while(mp1[kk]){
        cout << kk << " ";
        mp1[kk]--;
        if(mp1[kk]==0){
            mp1.erase(kk);
        }
    }
    for(auto i:mp[kk]){
        while (mp1[i])
        {
            cout << i << " ";
            mp1[i]--;
            if (mp1[i] == 0)
            {
                mp1.erase(i);
            }
        }
    }
    cout << endl;
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; cin>>t;
    while(t--){
        solve();
    }
}

