#include<iostream>
using namespace std;
int allIndexes(int input[],int n,int x,int output[]){
    if(n<1){
        return 0;
    }
    else if(n==1){
        if(input[0]==x){
            output[0]=0;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(input[n-1]==x){
            int index=n-1;
            output[allIndexes(input,n-1,x,output)]=index;
            return 1+allIndexes(input,n-1,x,output);
        }
        else{
            return allIndexes(input,n-1,x,output);
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
    int x;
    cin>>x;
    int output[n];
    int output_size=allIndexes(input,n,x,output);
    cout<<output_size<<endl;
    for(int i=0;i<output_size;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
5
1 3 3 4 5
3



*/