#include<iostream>
using namespace std;
void printArray(int a[][100],int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int a[100][100];
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    printArray(a,m,n);
    return 0; // if there are unused spaces in our array it automatically fills it with zeros.
}