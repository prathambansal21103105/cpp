#include<iostream>
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t>0){
        long long q;
        cin>>q;
        if(q<=36){
            cout<<0<<endl;
        }
        else{
            long long rest=q-36;
            long long every=7;
            long long rem=(q-36)%7;
            if(rem==0){
                cout<<rest/every<<endl;
            }
            else{
                cout<<(rest/every)+1<<endl;
            }
        }
        t-=1;
    }
    return 0;
}