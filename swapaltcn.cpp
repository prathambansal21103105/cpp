#include<iostream>
using namespace std;
void swap(int arr[],int n){
    if (n%2!=0){
        n-=1;
    }
    for(int i=0;i<n;i+=2){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
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
        swap(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}