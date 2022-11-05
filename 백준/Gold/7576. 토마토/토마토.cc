#include <iostream>
#include <queue>

using namespace std;

int **arr;
int answer;
bool **check;
queue<pair<int,int>> q;

void Make_arr(int row, int column) {
    arr = new int *[row];
    check = new bool *[row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int[column];
        check[i] = new bool[column];
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            check[i][j] = false;
        }
    }
}

void bfs(int xnum, int ynum) {
    int dx[4] = {0,1,-1, 0};
    int dy[4] = {1,0,0, -1};
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (0 <= ax && ax < xnum && 0 <= ay && ay < ynum && !check[ay][ax] && arr[ay][ax] != -1) {
                arr[ay][ax] = arr[y][x] + 1;
                check[ay][ax] = true;
                q.push(make_pair(ay,ax));
                answer = max(answer,arr[ay][ax]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int column, row;
    bool checks = false;
    cin >> column >> row;
    Make_arr(row, column);
    for(int i = 0 ; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cin >> arr[i][j];
            if( arr[i][j] == 0) checks = true;
            if( arr[i][j] == 1) {
                q.push(make_pair(i,j));
                check[i][j] = true;
            }
        }
    }
    if(!checks)   {
        cout << 0;
        return 0;
    }
    bfs( column, row);
    for(int i = 0 ; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(arr[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }
    cout<<answer - 1;
}