#include<iostream>
using namespace std;
void spiralPrint(int input[][100],int nRows,int nCols){
    int firstrow=0;
    int lastrow=nRows-1;
    int firstcol=0;
    int lastcol=nCols-1;
    while(firstrow<lastrow and firstcol<lastcol){
        for(int j=firstcol;j<=lastcol;j++){
            int i=firstrow;
            cout<<input[i][j]<<" ";
        }
        for(int i=firstrow+1;i<=lastrow;i++){
            int j=lastcol;
            cout<<input[i][j]<<" ";
        }
        for(int j=lastcol-1;j>=firstcol;j--){
            int i=lastrow;
            cout<<input[i][j]<<" ";
        }
        for(int i=lastrow-1;i>=firstrow+1;i--){
            int j=firstcol;
            cout<<input[i][j]<<" ";
        }
        firstrow+=1;
        firstcol+=1;
        lastrow-=1;
        lastcol-=1;
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
        spiralPrint(input,n,m);
        t-=1;
    }
    return 0;
}