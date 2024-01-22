#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        float n,m;
        cin>>n>>m;
        int div=int(n/m);
        int flag=0;
        if((n/m)==int(n/m)){
            if(div%2==0){
                cout<<"YES"<<endl;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }

        t-=1;
    }
    return 0;
}