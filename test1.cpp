#include<iostream>
using namespace std;
void Leaders(int input[],int n){
    int output[100];
    int j=0;
    int max=0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            output[j]=input[i];
            max=input[i];
            j+=1;
        }
        if(input[i]>=max and i!=n-1){
            max=input[i];
            output[j]=input[i];
            j+=1;
        }
    }
    for(int r=j-1;r>=0;r--){
        cout<<output[r]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    Leaders(input,n);
    return 0;
}