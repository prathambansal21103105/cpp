#include<iostream>
using namespace std;
int pairs(int arr[],int n,int x){
    int pairs1=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]+arr[j]==x){
                pairs1+=1;
            }
        }
    }
    return pairs1;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int ans=pairs(arr,n,x);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}