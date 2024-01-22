#include<iostream>
#define int long
using namespace std;

signed main(){
    int t;
    cin>>t;

    while(t>0){
        int x;
        cin>>x;

        int a=11;
        int b=111;
        int i=0;
        int flag=0;
        while(a*i<=x){
            int y=a*i;
            if((x-y)%b==0){
                flag=1;
                break;
            }
            i++;
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}