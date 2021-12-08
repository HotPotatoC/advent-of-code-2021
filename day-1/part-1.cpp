#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    vector<int> measurements;
    int increased_count = 0;

    int a;
    while (cin >> a)
        measurements.push_back(a);

    for (int i = 0; i < measurements.size(); i++)
    {
        if (i == 0)
            continue;

        if (measurements[i] > measurements[i - 1])
            increased_count++;
    }

    cout << increased_count << '\n';

    return 0;
}