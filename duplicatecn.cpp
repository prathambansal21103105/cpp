#include<iostream>
using namespace std;
int duplicate(int arr[],int n){
    int ans;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]==arr[j]){
                ans=arr[i];
                flag=1;
                break;
            }
        }
    }
    return ans;
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
        int duplicate1=duplicate(arr,n);
        cout<<duplicate1<<endl;
        t-=1;
    }
    return 0;
}