#include<iostream>
using namespace std;
int fact(int n){
    int i=1;
    int ans=1;
    while(i<=n){
        ans*=i;
        i+=1;
    }
    return ans;
}
int ncr(int n,int r){
    int ans;
    ans=fact(n)/(fact(n-r)*fact(r));
    return ans;
}
int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    int ans;
    ans=ncr(n,r);
    cout<<ans<<endl;
    return 0;
}