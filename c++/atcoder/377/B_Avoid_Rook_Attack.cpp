#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
    vector<string> grid(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    bool row_has_piece[8] = {false};
    bool col_has_piece[8] = {false};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] == '#')
            {
                row_has_piece[i] = true;
                col_has_piece[j] = true;
            }
        }
    }

    int safe_count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] == '.' && !row_has_piece[i] && !col_has_piece[j])
            {
                safe_count++;
            }
        }
    }

    cout << safe_count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution();

    return 0;
}
