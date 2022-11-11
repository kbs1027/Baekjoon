#include <iostream>
#include <list>

using namespace std;

int row, column, answer = 0;

list<pair<int,int>> lt;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int from, to, num, before, count = 0;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> from >> to;
        lt.emplace_back(to, from);
    }
    lt.sort();
    before = lt.front().first;
    lt.pop_front();
    count++;
    for(auto it : lt)
    {
        if(before <= it.second){
            count++;
            before = it.first;
        }
    }
    cout << count;
}
