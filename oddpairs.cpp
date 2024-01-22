#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long int n;
        cin>>n;
        if(n%2!=0){
            long int ans=((n*n)-1)/2;
            cout<<ans<<endl;
        }
        else{
            cout<<(n*n)/2<<endl;
        }
        t-=1;
    }
    return 0;
}