#include<iostream>
using namespace std;
void merge_sort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    else{
        int mid=(ei+si)/2;
        merge_sort(input,si,mid);
        merge_sort(input,mid+1,ei);
        int input1[ei-si+1];
        int count=si;
        int i=si;
        int j=mid+1;
        for(count=si;count<=ei;count+=1){
            if(i<=mid and j<=ei){
                if(input[i]<=input[j]){
                    input1[count]=input[i];
                    i+=1;
                }
                else{
                    input1[count]=input[j];
                    j+=1;
                }
            }
            else{
                if(i>mid){
                    input1[count]=input[j];
                    j+=1;
                }
                else{
                    input1[count]=input[i];
                    i+=1;
                }
            }
        }
        for(int i=si;i<=ei;i++){
            input[i]=input1[i];
        }
    }
}
void mergeSort(int input[], int n){
	// Write your code here
    // n=size
    merge_sort(input,0,n-1);
}
int main(){
    int length;
    cin>>length;
    int* input=new int[length];
    for(int i=0;i<length;i++){
        cin>>input[i];
    }
    mergeSort(input,length);
    for(int i=0;i<length;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}