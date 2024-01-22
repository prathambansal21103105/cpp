#include<iostream>
using namespace std;

int main(){
    int x;
    cin>>x;

    int y;
    cin>>y;

    x&=~(1<<y);
    cout<<x<<endl;

    return 0;
}