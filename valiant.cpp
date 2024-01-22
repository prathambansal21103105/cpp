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

        

        t-=1;
    }
    return 0;
}