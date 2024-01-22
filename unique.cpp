#include<iostream>
using namespace std;
int findUnique(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        int ans=findUnique(input,n);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}