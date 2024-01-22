#include<iostream>
using namespace std;
int findDuplicate(int arr[],int n){
    int fre[1000000]={0};
    for(int i=0;i<n;i++){
        fre[arr[i]]+=1;
        if(fre[arr[i]]==2){
            return arr[i];
        }
    }
    return 0;
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
        int ans=findDuplicate(input,n);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}