#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2;j++){
            if (input[j]>input[j+1]){
                int temp=input[j+1];
                input[j+1]=input[j];
                input[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}