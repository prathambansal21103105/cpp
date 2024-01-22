#include<iostream>
#include<algorithm>
#define int long
using namespace std;

signed main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;
        int c=1;
        int a=0;
        for(a=0;a<=n;a++){
            int b=n-c-a;
            if(a+b+c==n and __algo_gcd(a,b)==c and a!=b and b!=c and c!=a){
                cout<<a<<" "<<b<<" "<<c<<endl;
                break;
            }
        }
        t-=1;
    }
    return 0;
}