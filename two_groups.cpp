#include<iostream>
using namespace std;
#define endl '\n'
int main(){
    int t;
    cin>>t;
    while(t>0){
        int long long n;
        cin>>n;
        int long long arr[n];
        int long long sump=0;
        int long long sumn=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0){
                sump+=arr[i];
            }
            else{
                sumn+=arr[i];
            }
        }
        int long long maxarr=max(abs(sump),abs(sumn));
        int long long diff=abs(abs(sump)-abs(sumn));
        cout<<diff<<endl;
        t-=1;
    }
    return 0;
}