#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> co(v);
    sort(co.begin(), co.end());
    co.erase(unique(co.begin(), co.end()), co.end());
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(co.begin(), co.end(), v[i]);
        cout << it - co.begin() << ' ';
    }
}