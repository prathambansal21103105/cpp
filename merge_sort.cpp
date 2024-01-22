#include<iostream>
using namespace std;
void mergesort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    else{
        int mid=(si+ei)/2;
        mergesort(input,si,mid);
        mergesort(input,mid+1,ei);
        int new_arr[ei+1-si];
        int j=si;
        int k=mid+1;
        for(int i=0;i<=ei-si;i++){
            if(j<=mid and k<=ei){
                if(input[j]<input[k]){
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
        for(int i=0;i<=ei-si;i++){
            input[i+si]=new_arr[i];
        }
    }
}
void mergeSort(int input[],int n){
    mergesort(input,0,n-1);
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    mergeSort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}