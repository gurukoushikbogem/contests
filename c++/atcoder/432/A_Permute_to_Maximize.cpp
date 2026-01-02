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

void solution()
{
    int a,b,c;
    cin>>a>>b>>c;
    string t1=to_string(a)+to_string(b)+to_string(c);
    string t2=to_string(a)+to_string(c)+to_string(b);
    string t3=to_string(b)+to_string(a)+to_string(c);
    string t4=to_string(b)+to_string(c)+to_string(a);
    string t5=to_string(c)+to_string(a)+to_string(b);
    string t6=to_string(c)+to_string(b)+to_string(a);
    int d1=stoi(t1);
    int d2=stoi(t2);
    int d3=stoi(t3);
    int d4=stoi(t4);
    int d5=stoi(t5);
    int d6=stoi(t6);
    int ans=max({d1,d2,d3,d4,d5,d6});
    println(ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t=1;
    while(t--)
    {
       solution();
    }
    return 0;
}