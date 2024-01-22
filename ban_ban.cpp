#include<iostream>
using namespace std;
#define endl '\n'
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        cout<<(n+1)/2<<endl;
        for(int i=0;i<(n+1/2);i++){
            int s=(i*3)+1;
            cout<<s<<" "<<(n*3)-s+1<<endl;
        }
        t-=1;
    }
    return 0;
}