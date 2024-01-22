#include<iostream>
using namespace std;
void partition(int input[],int si,int count,int ei){
    int i=si;
    int j=count+1;
    int k=si;
    for(k=si;k<=ei;k++){
        if(i<=count-1 and j<=ei){
        if(input[i]>=input[count] and input[j]<input[count]){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i+=1;
            j+=1;
        }
        else if(input[i]<input[count]){
            i+=1;
        }
        else if(input[j]>=input[count]){
            j+=1;
        }
        }
        else{
            break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int a=input[0];
    int count=0;
    for(int i=0;i<n;i++){
        if(input[i]<a){
            count+=1;
        }
    }
    int temp=input[count];
    input[count]=input[0];
    input[0]=temp;
    partition(input,0,count,n-1);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}