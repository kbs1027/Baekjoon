#include <iostream>

using namespace std;

int arr[1000001];
int main(){
    int low,high;
    cin>>low>>high;
    if(low<2)   low=2;
    if(high>1000000)    high=1000000;
    for(int i=2;i<high+1;i++){
        arr[i]=i;
    }
    for(int i=2;i<high+1;i++){
        if(arr[i]==0)   continue;
        for(int j=2*i;j<=high;j+=i){
            arr[j]=0;
        }
    }
    for(int i=0;i<low;i++){
        arr[i]=0;
    }
    for(int i=low;i<high+1;i++){
        if(arr[i]!=0)   cout<<arr[i]<<"\n";
    }
}