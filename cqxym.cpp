#include<iostream>
#define int long
using namespace std;

signed main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;
        
        if(n==1){
            cout<<1<<endl;
        }
        else{
            int x=2*n;
            int ans=1;
            int flag=0;
            for(int i=x;i>=1;i--){
                ans=ans*i;
                if(flag==0){
                    ans=ans/2;
                    flag=1;
                    continue;
                }
                ans=ans%(1000000007);
            }
            ans=ans%(1000000007);
            cout<<ans<<endl;
        }

        t-=1;
    }
}