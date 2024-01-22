#include<iostream>
using namespace std;
int partition(int input[],int si,int ei){
    int count=0;
    int x=input[si];
    for(int i=si;i<=ei;i++){
        if(input[i]<x){
            count+=1;
        }
    }
    int temp=input[si+count];
    input[si+count]=input[si];
    input[si]=temp;
    int i=si;
    int j=ei;
    while(i<=si+count-1 and j>=si+count+1){
        int a;
        int b;
        int flag=0;
        if(input[i]<x){
            i+=1;
        }
        else{
            i+=0;
            flag+=1;
        }
        if(input[j]>=x){
            j-=1;
        }
        else{
            j+=0;
            flag+=1;
        }
        if(flag==2){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
        }
    }
    return si+count;
}
void quick_Sort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    else{
        int count=partition(input,si,ei);
        quick_Sort(input,si,count-1);
        quick_Sort(input,count+1,ei);
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    quickSort(input,0,n-1);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
} 