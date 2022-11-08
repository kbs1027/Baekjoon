#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int counts=100000;
bool check[100001] = {false,};

queue<pair<int, int>> q;

void bfs(int start, int end){
    q.push(make_pair(start,0));
    while(!q.empty()) {
        int s = q.front().first;
        int count = q.front().second;
        check[s] = true;
        if(q.front().first == end)    counts = min(counts, count);
        if(!check[s*2] && s*2 <= 100000 && s*2 >=0) q.push(make_pair(s*2,count+1));
        if(!check[s-1] && s-1 <= 100000 && s-1 >=0) q.push(make_pair(s-1,count+1));
        if(!check[s+1] && s+1 <= 100000 && s+1 >=0) q.push(make_pair(s+1,count+1));
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int start, end;
    cin >> start >> end;
    bfs(start, end);
    cout<< counts;
}