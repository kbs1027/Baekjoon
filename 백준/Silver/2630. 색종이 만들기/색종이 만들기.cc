#include <iostream>
#include <vector>

using namespace std;

int **arr;
int one_part = 0, zero_part = 0;

void Make_arr(int num){
    arr= new int *[num];
    for(int i = 0; i < num; i++) {
        arr[i] = new int[num];
    }
}

void square(int xs, int ys, int size) {
    int zero_num = 0;
    int one_num = 0;
    for(int i = xs; i < xs + size; i++) {
        for(int j = ys; j < ys + size; j++) {
            if(arr[i][j] == 1)  one_num++;
            else    zero_num++;
        }
    }
    if(zero_num == 0)   {
        one_part++;
        return;
    }
    else if(one_num == 0) {
        zero_part++;
        return;
    }
    for(int i = xs; i < xs + size/2; i++) {
        for(int j = ys; j < ys + size/2; j++) {
            if(arr[i][j] == 1)  one_num++;
            else    zero_num++;
        }
    }
    if(zero_num == 0)   one_part++;
    else if(one_num == 0) zero_part++;
    else square(xs,ys,size/2);

    zero_num = 0;
    one_num = 0;
    for(int i = xs; i < xs + size/2; i++) {
        for(int j = ys + size / 2; j < ys + size; j++) {
            if(arr[i][j] == 1)  one_num++;
            else    zero_num++;
        }
    }
    if(zero_num == 0)   one_part++;
    else if(one_num == 0) zero_part++;
    else square(xs,ys + size/2,size/2);

    zero_num = 0;
    one_num = 0;
    for(int i = xs + size / 2; i < xs + size; i++) {
        for(int j = ys; j < ys + size/2; j++) {
            if(arr[i][j] == 1)  one_num++;
            else    zero_num++;
        }
    }
    if(zero_num == 0)   one_part++;
    else if(one_num == 0) zero_part++;
    else square(xs + size/2,ys,size/2);

    zero_num = 0;
    one_num = 0;
    for(int i = xs + size / 2; i < xs + size; i++) {
        for(int j = ys + size /2; j < ys + size; j++) {
            if(arr[i][j] == 1)  one_num++;
            else    zero_num++;
        }
    }
    if(zero_num == 0)   one_part++;
    else if(one_num == 0) zero_part++;
    else square(xs + size/2,ys + size/2,size/2);
}

int main() {
    int num;
    cin >> num;
    Make_arr(num);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    square(0, 0, num);
    cout << zero_part << "\n" << one_part;
}