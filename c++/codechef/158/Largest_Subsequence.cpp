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



void solution()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int c=0;
    string v;
    for(int i=0;i<n;i++)
    {
        if (v.size()>0 && v[v.size()-1] != s[i])
        {
            //cout<<i<<" ";
            c++;
        }
        v+=s[i];
    }
   // cout<<c<<endl;
    if(c%2==0){
        cout<<v.size()<<endl;
    }
    else{
        int c1=1;
        int i=0;
        while(v[i]==v[i+1]){
            c1++;
            i++;
        }
        int c2=1;
        i=v.size()-1;
        while(v[i]==v[i-1]){
            c2++;
            i--;
        }
        cout<<v.size()-min(c1,c2)<<endl;
    }

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