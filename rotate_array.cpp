#include<iostream>
using namespace std;
void rotate(int input[],int d,int n){
    int arr[n];
    int count=0;
    for(int i=d;i<n;i++){
        arr[count]=input[i];
        count+=1;
    }
    for(int i=0;i<d;i++){
        arr[count]=input[i];
        count+=1;
    }
    for(int i=0;i<n;i++){
        arr[i]=input[i];
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