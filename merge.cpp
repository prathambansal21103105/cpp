#include<iostream>
using namespace std;
void partition(int input[], int si, int mid, int ei){
    int i=si;
    int j=ei;
    while(i<mid and j>mid){
        if(input[i]>=input[mid] and input[j]<input[mid]){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
        else if(input[i]<input[mid]){
            i++;
        }
        else if(input[j]>=input[mid]){
            j--;
        }
        else{
            break;
        }
    }
}
int main(){
    int arr[7]={5,6,3,4,1,2,7};
    int mid=3;
    partition(arr,0,3,6);
    for(int i=0;i<1+2+1+3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}