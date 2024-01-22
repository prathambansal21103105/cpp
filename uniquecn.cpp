#include<iostream>
using namespace std;
int findunique(int arr[],int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1^=arr[i];
    }
    return xor1;
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
        int unique=findunique(arr,n);
        cout<<unique<<endl;
        t-=1;
    }
    return 0;
}