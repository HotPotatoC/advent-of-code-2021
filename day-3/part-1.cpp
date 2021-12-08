#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

#define ull unsigned long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    vector<string> binaries;
    string s;
    while (cin >> s)
        binaries.push_back(s);

    string gamma_rate;
    string epsilon_rate;

    for (int i = 0; i < binaries[0].size(); i++)
    {
        int bit_0_count = 0;
        int bit_1_count = 0;
        for (int j = 0; j < binaries.size(); j++)
        {
            if (binaries[j][i] == '0')
                bit_0_count++;
            if (binaries[j][i] == '1')
                bit_1_count++;
        }

        if (bit_0_count > bit_1_count)
        {
            gamma_rate.append("0");
            epsilon_rate.append("1");
        }
        if (bit_0_count < bit_1_count)
        {
            gamma_rate.append("1");
            epsilon_rate.append("0");
        }
    }

    ull gamma_rate_dec = stoull(gamma_rate, 0, 2);
    ull epsilon_rate_dec = stoull(epsilon_rate, 0, 2);
    ull power_consumption = gamma_rate_dec * epsilon_rate_dec;

    cout << power_consumption << '\n';

    return 0;
}