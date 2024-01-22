#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n,m;
        cin>>n>>m;
        long long input[n];
        for(long long i=0;i<n;i++){
            cin>>input[i];
        }
        long long prev[n];
        for(long long i=0;i<n;i++){
            prev[i]=input[i];
        }
        int flag=0;
        int nbs[n];
            for(int i=0;i<n;i++){
                int num=0;
                if(i-1>=0){
                    if(input[i-1]>0){
                        num+=1;
                    }
                }
                if(i+1<n){
                    if(input[i+1]>0){
                        num+=1;
                    }
                }
                nbs[i]=num;
            }
        while(m>0){
            flag=0;
            for(int i=0;i<n;i++){
                if(nbs[i]==1){
                    input[i]=abs(input[i]);
                }
                else{
                    input[i]=-1*(abs(input[i]));
                }
            }
            // for(int i=0;i<n;i++){
            //     if(input[i]==prev[i]){
            //         continue;
            //     }
            //     else{
            //         flag=1;
            //         break;
            //     }
            // }
            // if(flag==0){
            //     break;
            // }
            
            m-=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(input[i]>0){
                ans+=1;
            }
        }
        // if(n>3){
        //     cout<<2*ans<<endl;
        // }
        // else{
        cout<<ans<<endl;
        // }
        t-=1;
    }
    return 0;
}