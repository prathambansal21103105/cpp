#include<iostream>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t>0){
        int n,q;
        cin>>n>>q;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        int sum=0;
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            if(input[i]%2!=0){
                odd+=1;
            }
            else{
                even+=1;
            }
            sum+=input[i];
        }
        for(int i=0;i<q;i++){
            int o,r;
            cin>>o>>r;
            if(o==0){
                if(r%2==0){
                    sum=sum+(even*r);
                }
                else{
                    sum=sum+(even*r);
                    odd=odd+even;
                    even=0;
                }
            }
            else{
                if(r%2==0){
                    sum=sum+(odd*r);
                }
                else{
                    sum=sum+(odd*r);
                    even=even+odd;
                    odd=0;
                }
            }
            cout<<sum<<endl;
        }
        t-=1;
    }
    return 0;
}