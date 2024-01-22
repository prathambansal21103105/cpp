#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        int seconds=(60*x)-5-31;
        int ans=seconds/30;
        cout<<ans+2<<endl;
        t-=1;
    }
    return 0;
} 