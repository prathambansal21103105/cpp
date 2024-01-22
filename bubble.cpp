#include<iostream>
using namespace std;
void bubble_Sort(int input[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (input[j]>input[j+1]){
                int temp=input[j+1];
                input[j+1]=input[j];
                input[j]=temp;
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
    bubble_Sort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}