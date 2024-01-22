#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,x,y;
        cin>>n>>x>>y;
        int sum;
        sum=x+(2*y);
        if (sum<=n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}