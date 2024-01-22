#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
    int n,x;
    cin>>n>>x;
    int loop1;
    loop1=3*x;
    int ans;
    ans=n/loop1;
    cout<<ans<<endl;
    t-=1;
    }
    return 0;
}
