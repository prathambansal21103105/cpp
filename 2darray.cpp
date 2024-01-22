#include<iostream>
using namespace std;
int main(){
    int input[100][100];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>input[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}