#include<iostream>
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;

        long long x=((n%mod)*((n+1)%mod))%mod;
        long long y=((((4*n)-1)%mod)*(337%mod))%mod;
        long long ans=((x%mod)*(y%mod))%mod;
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}