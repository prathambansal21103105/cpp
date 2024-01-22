#include<iostream>
using namespace std;
void sortZeroesAndOne(int input[],int size){
    int nzeroes=0;
    for(int i=0;i<size;i++){
        if (input[i]==0){
            nzeroes+=1;
        }
    }
    for(int i=0;i<size;i++){
        if (i<nzeroes){
            input[i]=0;
        }
        else{
            input[i]=1;
        }
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
        sortZeroesAndOne(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        t-=1;
    }
    return 0;
}