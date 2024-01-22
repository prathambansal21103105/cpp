#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int new_arr[n];
    int j=0;
    int k=((n-1)/2)+1;
    int mid=(n-1)/2;
    for(int i=0;i<n;i++){
        if(j<=mid and k<=n-1){
        if(input[j]<=input[k]){
            new_arr[i]=input[j];
            j+=1;
        }
        else{
            new_arr[i]=input[k];
            k+=1;
        }
        }
        else{
            if(j>mid){
                new_arr[i]=input[k];
                k+=1;
            }
            else{
                new_arr[i]=input[j];
                j+=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        input[i]=new_arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}