#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num, input;
    cin >> num;
    priority_queue<int> pq;
    for(int i = 0; i < num; i++) {
        cin >> input;
        if(input == 0){
            if(pq.empty())  cout << input <<"\n";
            else{
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(input);
        }
    }
}