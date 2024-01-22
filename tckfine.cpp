#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        int p;
        cin>>p;
        int q;
        cin>>q;
        cout<<(p-q)*x<<endl;
        t-=1;
    }
    return 0;
}