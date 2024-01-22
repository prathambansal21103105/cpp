#include<iostream>
using namespace std;
int subsetSumToK(int input[],int n,int output[][50],int k){
    if(input[0]==k){
        output[0][0]+=1;
        output[0][output[0][0]]=k;
        return 1;
    }   
    else{
        int small1=subsetSumToK(input+1,n-1,output,k-input[0]);
        int small2=subsetSumToK(input+1,n-1,output[small1][],k);
        for(int i=0;i<small1;i++){
            output[i][0]+=1;
            for(int j=output[i][0];j>=2;j--){
                output[i][j]=output[i][j-1];
            }
            output[i][1]=input[0];
        }
        return small1+small2;
    } 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int output[n][50];
    int ans=subsetSumToK(arr,n,output,k);
    for(int i=0;i<n;i++){
        for(int j=0;j<ans;j++){
            cout<<output[i][j]<<" ";
        }
    }
    cout<<endl;
    return 0;
}