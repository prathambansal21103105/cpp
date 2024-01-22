#include<iostream>
using namespace std;
// void printSubsetsOfArray(int input[],int n){
//     if(n==0){
//         cout<<" "<<endl;
//         cout<<" ";
//         return;
//     }
//     else{
//         cout<<input[0]<<" ";
//         printSubsetsOfArray(input+1,n-1);
//         cout<<endl;
//         printSubsetsOfArray(input+1,n-1);
//     }
// }
void print(int input[],int n,int output[]){
    if(n==0){
        return 0;
    }
    else if(n==1){
        print(input+1,n-1,output);
        output[0]=input[0];
        print(input+1,n-1,output+1);
    }
    else{
        print(input+1,n-1,output);
        output[0]=input[0];
        print(input+1,n-1,output+1);
    }
    
}
void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    print(input,size,output);
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    printSubsetsOfArray(input,n);
    return 0;
}