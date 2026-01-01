#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int Generate_Secret(const vector<pair<int, int>> &points, int K)
{
    int secret = 0;
    for (int i = 0; i < K; ++i){
        int xi = points[i].first;
        int yi = points[i].second;

        int num = 1, den = 1;

        for (int j = 0; j < K; ++j)
        {
            if (i != j)
            {
                num *= -points[j].first;
                den *= (xi - points[j].first);
            }
        }

        secret += (yi * num / den);
    }

    return secret;
}

int calculate_Y(int x, int a, int b, int c)
{
    return (a * x * x + b * x + c);
}

void secret_sharing(vector<pair<int, int>> &points, int N, int K)
{
    for (int j = 1; j <= N; ++j)
    {
        int x = j;
        int y = calculate_Y(x, points[0].second, points[1].second, points[2].second);

        points[j - 1] = {x, y};
    }
}

int main()
{
    vector<pair<int, int>> points(3); 
    int N = 4;                        
    int K = 3;                        
    
    cin >> points[0].second >> points[1].second >> points[2].second;
    secret_sharing(points, N, K);

    for (int i = 0; i < N; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].first << ", " << points[i].second << ")" << endl;
    }

    if (N < K)
    {
        return 1;
    }

    vector<pair<int, int>> selected_shares(points.begin(), points.begin() + K);

    int a = Generate_Secret(selected_shares, K);

    cout << "Reconstructed coefficient of x-square (a) is: " << a << endl;

    return 0;
}
