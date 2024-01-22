#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int w,x,y,z;
        cin>>w>>x>>y>>z;
        int ans=w+(z*(x-y));
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}