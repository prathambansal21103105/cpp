#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;
        long long bn[n+1];
        for(int i=0;i<n+1;i++){
            cin>>bn[i];
        }
        long long last=bn[n];
        for(int i=0;i<n;i++){
            cout<<(bn[i]^last)<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}