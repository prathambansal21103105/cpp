#include<iostream>
using namespace std;
void insertion(int input[],int n){
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if (input[i]<input[j]){
                int temp=input[j];
                input[j]=input[i];
                input[i]=temp;
                i-=1;
            }
            else{
                break;
            }
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
    insertion(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;   
    return 0;
}