#include<iostream>
using namespace std;
void mergesort(int input[], int si, int ei){
    if(si>=ei){
        return;
    }
    else{
        int mid=(si+ei)/2;
        mid=mid+1;
        mergesort(input,si,mid-1);
        mergesort(input,mid,ei);
        int i=si;
        int j=mid;
        int k=0;
        int arr[ei-si+1];
        while(i<mid and j<ei+1){
            if(input[i]<input[j]){
                arr[k]=input[i];
                i++;
                k++;
            }
            else{
                arr[k]=input[j];
                j++;
                k++;
            }
        }
        while(i<mid){
            arr[k]=input[i];
            i++;
            k++;
        }
        while(j<ei+1){
            arr[k]=input[j];
            j++;
            k++;
        }
        for(int r=0;r<ei-si+1;r++){
            input[si+r]=arr[r];
        }
    }
}

void mergeSort(int input[], int size){
    mergesort(input,0,size-1);
}
int main(){
    int n;
    n=7;
    int input[7]={27,17,2,13,19,7,18};
    mergeSort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}