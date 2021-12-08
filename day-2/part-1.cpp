#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    vector<pair<string, int>> directions;
    string line;

    while (getline(cin, line))
    {
        string direction = line.substr(0, line.find(' '));
        int amount = stoi(line.substr(line.find(' ') + 1));

        directions.push_back(make_pair(direction, amount));
    }

    int horizontal_position = 0;
    int depth = 0;
    for (auto &direction : directions)
    {
        if (direction.first == "forward")
            horizontal_position += direction.second;

        if (direction.first == "down")
            depth += direction.second;

        if (direction.first == "up")
            depth -= direction.second;
    }

    cout << horizontal_position * depth << '\n';

    return 0;
}