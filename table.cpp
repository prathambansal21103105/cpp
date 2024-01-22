#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=10;i++){
        int ans;
        ans=n*i;
        cout<<n<<"*"<<i<<"="<<ans<<endl;
    }
    return 0;
}