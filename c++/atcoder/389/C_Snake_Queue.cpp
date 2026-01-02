#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    deque<pair<long long, long long>> queue;
    long long offset = 0;

    while (Q--)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            long long l;
            cin >> l;
            if (queue.empty())
            {
                queue.push_back({0, l});
            }
            else
            {
                long long head = queue.back().first + queue.back().second;
                queue.push_back({head, l});
            }
        }
        else if (query_type == 2)
        {
            long long m = queue.front().second;
            queue.pop_front();
            offset += m;
        }
        else if (query_type == 3)
        {
            long long k;
            cin >> k;
            k--;
            cout << queue[k].first - offset << endl;
        }
    }
    return 0;
}
