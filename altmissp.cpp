#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int xorsum=0;
        while(n>0){
            int ai;
            cin>>ai;
            xorsum=xorsum^ai;
            n-=1;
        }
        cout<<xorsum<<endl;
        t-=1;
    }
    return 0;
}