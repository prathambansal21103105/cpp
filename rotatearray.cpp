#include<iostream>
using namespace std;
void rotate(int input[],int d,int n){
    int arr[n];
    int j=0;
    for(int i=0;i<n;i++){
        if (i<=d-1){
            arr[n-(d-i)]=input[i];
        }
        else{
            arr[j]=input[i];
            j+=1;
        }
    }
    for(int i=0;i<n;i++){
        input[i]=arr[i];
    }
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        int d;
        cin>>d;
        rotate(input,d,n);
        for(int i=0;i<n;i++){
            cout<<input[i]<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}