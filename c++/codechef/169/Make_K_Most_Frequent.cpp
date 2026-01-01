#include<bits/stdc++.h>
#define ll long long
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

ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    ll ans = 1;
    while (b > 0)
    {
        if(b&1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

bool help1(vector<vector<int>> &v,int i,int k)
{
    int c1=v[i][k];
    for(auto j:v[i]){
        if(j>c1){
            return false;
        }
    }
    return true;
}

bool help2(vector<vector<int>> &v,int i,int k)
{
    int c2=v[v.size()-1][k];
    if(i>0)
    c2-=v[i-1][k];
    for(int j=0;j<21;j++){
        if(v[v.size()-1][j]-v[i][j]>c2){
            return false;
        }
    }
    return true;
}

void solution()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int kk=mp[k];
    int ans=0;
    bool flag=true;
    for(auto i:mp){
        if(i.second>mp[k]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> v;
    vector<int> temp(21);
    for(int i=0;i<n;i++){
        temp[a[i]]++;
        v.push_back(temp);
    }

    for(int i=0;i<n;i++){
        if(a[i]==k && (help1(v,i,k) || help2(v,i,k))){
            cout<<1<<endl;
            return;
        }
    }
    cout<<2<<endl;
}
int main()
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