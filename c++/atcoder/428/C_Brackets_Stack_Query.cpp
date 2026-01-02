#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(), (v).end())
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define mod (long long)(1e9 + 7)
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define vc vector<char>
#define vpii vector<pair<long long, long long>>
#define endl "\n"
#define mpii map<long long, long long>
#define umpii unordered_map<long long, long long>
#define mpci map<char, long long>
using namespace std;
template <class T>
void input(vector<T> &a)
{
    for (auto &x : a)
        cin >> x;
}

template <class T>
void print(vector<T> &a)
{
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

template <class T>
void print(T x) { cout << x << " "; }

template <class T>
void println(T x) { cout << x << "\n"; }

void solution()
{
    int q;
    cin >> q;
    stack<pair<int, int>> st;
    st.push({0, 0});

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            char ch;
            cin >> ch;
            int up = (ch == '(') ? 1 : -1;
            int lb = st.top().first, last_min = st.top().second;
            int nb = lb + up, nm = min(last_min, nb);
            st.push({nb, nm});
        }
        else
        {
            if(!st.empty())
            st.pop();
        }
        if (st.top().first == 0 && st.top().second >= 0)
        {
            yes;
        }
        else
        {
            no;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solution();
    }
    return 0;
}