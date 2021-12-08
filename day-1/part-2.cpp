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
    int larger_sum_count = 0;

    int a;
    while (cin >> a)
        measurements.push_back(a);

    int current_sum = measurements[0] + measurements[1] + measurements[2];
    int prev_sum = current_sum;

    for (int i = 1; i <= measurements.size() - 3; i++)
    {
        current_sum += measurements[i + 2] - measurements[i - 1];
        if (current_sum > prev_sum)
        {
            larger_sum_count++;
        }
        prev_sum = current_sum;
    }

    cout << larger_sum_count << '\n';

    return 0;
}