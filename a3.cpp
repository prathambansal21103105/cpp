#include<iostream>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    int ans;
    ans=1;
    if (n==0){
        cout<<1<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            ans*=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}