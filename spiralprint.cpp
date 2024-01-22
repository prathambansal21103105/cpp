#include<iostream>
using namespace std;
void spiralPrint(int input[][100],int nRows,int nCols){
    int firstrow=0;
    int lastrow=nRows-1;
    int firstcol=0;
    int lastcol=nCols-1;
    int count=0;
    int total=0;
    while(total<nRows*nCols){
        for(int i=count;i<nCols-count;i++){
            cout<<input[firstrow+count][i]<<" ";
            total+=1;
        }
        for(int i=count+1;i<nRows-count;i++){
            cout<<input[i][lastcol-count]<<" ";
            total+=1;
        }
        for(int i=nCols-count-2;i>=count;i--){
            cout<<input[lastrow-count][i]<<" ";
            total+=1;
        }
        for(int i=nRows-count-2;i>=count+1;i--){
            cout<<input[i][firstcol+count]<<" ";
            total+=1;
        }
        count+=1;
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