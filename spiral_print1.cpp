#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        int input[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>input[i][j];
            }
        }
        int firstrow=0;
        int lastrow=n-1;
        int firstcol=0;
        int lastcol=m-1;
        while(firstrow<lastrow and firstcol<lastcol){
            for(int i=firstcol;i<lastcol;i++){
                cout<<input[firstrow][i]<<" ";
            }
            for(int i=firstrow;i<lastrow;i++){
                cout<<input[i][lastcol]<<" ";
            }
            for(int i=lastcol;i>firstcol;i--){
                cout<<input[lastrow][i]<<" ";
            }
            for(int i=lastrow;i>firstrow;i--){
                cout<<input[i][firstcol]<<" ";
            }
            firstrow++;
            lastrow--;
            firstcol++;
            lastcol--;
            if(firstrow==lastrow){
                for(int i=firstcol;i<=lastcol;i++){
                    cout<<input[firstrow][i];
                }
            }
        }
        t-=1;
    }
    return 0;
}