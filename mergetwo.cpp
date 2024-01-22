#include<iostream>
using namespace std;
void mergearray(int input1[],int size1,int input2[],int size2,int ans[]){
    int i=0,j=0,k=0;
    while(i<size1 and j<size2){
        if(input1[i]<input2[j]){
            ans[k++]=input1[i++];
        }
        else{
            ans[k++]=input2[j++];
        }
    }
    while(i<size1){
        ans[k++]=input1[i++];
    }
    while(j<size2){
        ans[k++]=input2[j++];
    }
}
  

int main(){
    int t;
    cin>>t;
    while(t>0){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int ans[n1+n2];
    mergearray(arr1,n1,arr2,n2,ans);
    for(int i=0;i<n1+n2;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}