#include<iostream>
using namespace std;
void intersection(int arr1[],int arr2[],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            if (arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                int temp=arr2[j];
                arr2[j]=arr2[i];
                arr2[i]=temp;
                break;
            }
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr1[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        int m;
        cin>>m;
        int arr2[m];
        for(int i=0;i<m;i++){
            cin>>arr2[m];
        }
        intersection(arr1,arr2,n,m);
        t-=1;
    }
    return 0;
}