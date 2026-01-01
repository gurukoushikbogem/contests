#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(),(v).end())
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod (long long)(1e9 + 7)
#define vi vector<long long>
#define vvi vector< vector <long long> >
#define vc vector<char>
#define vpii vector< pair<long long,long long> >
#define endl "\n"
#define mpii map<long long,long long>
#define umpii unordered_map<long long, long long> 
#define mpci map<char,long long>
using namespace std;
template<class T>
void input(vector<T>&a){ for(auto &x : a)cin>>x; }

template<class T>
void print(vector<T>&a){
    for(auto &x: a)cout<<x<<" ";
    cout<<endl;
}

template<class T>
void print(T x){cout<<x<<" ";}

template<class T>
void println(T x){ cout<<x<<"\n";}


int setbit(int n)
{
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}

void solution()
{
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,vector<int>>mp;
    map<int,vector<int>>mp1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int k=setbit(a[i]);
        mp[k].push_back(a[i]);
        mp1[k].push_back(i);
    }

    for(auto i:mp){
        vector<int>ty=i.second;
        sort(ty.begin(),ty.end());
        mp[i.first]=ty;
    }

    vector<int>temp(n);

    for(auto i:mp1){
        vector<int>ty=i.second;
        vector<int>tx=mp[i.first];
        for(int j=0;j<ty.size();j++){
            temp[ty[j]]=tx[j];
        }
    }

    for(int i=0;i<n-1;i++){
        if(temp[i+1]<temp[i]){
            cout<<"No\n";
            return;
        }
    }

    cout<<"Yes\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
       solution();
    }
    return 0;
}