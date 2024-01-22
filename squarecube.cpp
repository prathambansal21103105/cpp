#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int square,cube;
        square=i*i;
        cube=square*i;
        cout<<i<<" "<<"->"<<square<<" "<<cube<<endl;
    }
    return 0;
}