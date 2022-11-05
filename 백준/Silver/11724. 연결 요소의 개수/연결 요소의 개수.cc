#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> vec[1001];
bool check[1001] = {false,};
int answer = 0;

void dfs(int node){
    check[node] = true;
    for(int i = 0; i < vec[node].size(); i++){
        int temp = vec[node][i];
        if(!check[temp]){
            dfs(temp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int x, y;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i = 1; i <= N; i++){
        if(!check[i]) {
            answer++;
            dfs(i);
        }
    }
    cout << answer;
}