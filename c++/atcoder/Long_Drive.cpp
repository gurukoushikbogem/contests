#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;
        cin >> X >> Y;

        int initial_distance = X * 10;
        int required_distance = 10 * Y;
        int distance_difference = required_distance - initial_distance;

        int speed_difference = 100 - Y;

        int min_hours = ceil(static_cast<double>(distance_difference) / speed_difference);

        cout << min_hours << endl;
    }

    return 0;
}
