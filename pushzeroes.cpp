#include<iostream>
using namespace std;
void pushZeroesEnd(int input[],int size){
    int count=-1;
    for(int i=0;i<size;i++){
        if (input[i]!=0){
            int add=input[i];
            count+=1;
            input[count]=add;
        }
        else{
            continue;
        }
    }
    for(int i=count+1;i<size;i++){
        input[i]=0;
    }
}
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        pushZeroesEnd(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}