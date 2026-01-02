#include <iostream>
#include <vector>
using namespace std;

vector<string> generateCarpet(int N)
{
    if (N == 0)
    {
        return {"#"};
    }
    vector<string> smallerCarpet = generateCarpet(N - 1);
    int size = smallerCarpet.size();
    vector<string> carpet(3 * size, string(3 * size, ' '));
    for (int i = 0; i < 3 * size; ++i)
    {
        for (int j = 0; j < 3 * size; ++j)
        {
            if (i / size == 1 && j / size == 1)
            {
                carpet[i][j] = '.';
            }
            else
            {
                carpet[i][j] = smallerCarpet[i % size][j % size];
            }
        }
    }
    return carpet;
}

int main()
{
    int N;
    cin >> N;
    vector<string> carpet = generateCarpet(N);
    for (const string &line : carpet)
    {
        cout << line << endl;
    }
    return 0;
}
