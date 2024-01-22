#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int long n;
        cin>>n;
        int long a[n];
        int long suma=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            suma+=a[i];
        }
        int long b[n];
        int long sumb=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            sumb+=b[i];
        }
        if(suma!=sumb){
            cout<<-1<<endl;
        }
        else{
            int long max=0;
            for(int i=0;i<n;i++){
                int long diff=a[i]-b[i];
                if(diff>0){
                    max+=diff;
                }
            }
            cout<<max<<endl;
        }
        t-=1;
    }
    return 0;
}