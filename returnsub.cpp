#include<iostream>
using namespace std;
int subset(int input[],int n,int output[][20]){
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    else{
        int smalloutput=subset(input+1,n-1,output);
        for(int i=0;i<smalloutput;i++){
            output[smalloutput+i][0]=output[i][0]+1;
            output[smalloutput+i][1]=input[0];
        }
        for(int i=0;i<smalloutput;i++){
            if(i>0){
            for(int j=2;j<2+output[i][0];j++){
                output[smalloutput+i][j]=output[i][j-1];
            }
            }
        }
        return 2*smalloutput;
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int output[35000][20];
    int size=subset(input,n,output);
    for(int i=0;i<size;i++){
        for(int j=0;j<=output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}