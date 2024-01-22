#include<iostream>
using namespace std;
void wavePrint(int input[][100],int nRows,int mCols){
    for(int j=0;j<mCols;j++){
        if (j%2==0){
            for(int i=0;i<nRows;i++){
                cout<<input[i][j]<<" ";
            }
        }
        else{
            for(int i=nRows-1;i>=0;i--){
                cout<<input[i][j]<<" ";
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        int input[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>input[i][j];
            }
        }
        wavePrint(input,n,m);
        t-=1;
    }
    return 0;
}