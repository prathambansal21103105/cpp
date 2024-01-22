#include<iostream>
using namespace std;
int subsetSumToK(int input[],int n,int output[][50],int k){
    if(n==0){
        output[0][0]=0;
        sum=0;
        return 1;
    }
    else if(input[0]<=k and input[0]+sum<=k){
        output[0][0]+=1;
        output[0][output[0][0]]=input[0];
        subsetSumToK(input+1,n-1,output,k-input[0]);
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    int output[35000][50];
    int size=subsetSumToK(input,n,output,k);
    for(int i=0;i<size;i++){
        for(int j=0;j<output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}