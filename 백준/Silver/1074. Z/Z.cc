#include <iostream>
#include <cmath>

using namespace std;

int row, column, answer = 0;

void Z(int x, int y, int size, int count){
    int k = size * size / 4;
    int resize = size / 2;
    if(column == x && row == y)
    {
        cout << count;
        return;
    }
    else if(column < x + size && row < y + size && column >= x && row >= y)
    {
        Z(x, y,resize, count);
        Z(x + resize, y, resize, count + k);
        Z(x, y + resize, resize, count + k * 2);
        Z(x + resize, y + resize, resize, count + k * 3);
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num >> row >> column;
    Z(0, 0, pow(2, num), 0);
}
