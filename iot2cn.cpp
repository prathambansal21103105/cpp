#include<iostream>
using namespace std;
void intersection(int input1[],int input2[],int size1,int size2){

    for(int i=0;i<size1;i++){
        int max1=input1[i];
        for(int j=i+1;j<size1;j++){
            if (input1[j]>max1){
                max1=input1[j];
                int temp=input1[i];
                input1[i]=input1[j];
                input1[j]=temp;
            }
        }
    }
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
            cin>>arr2[i];
        }
        intersection(arr1,arr2,n,m);
        t-=1;
    }
    return 0;
}