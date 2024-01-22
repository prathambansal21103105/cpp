#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=a[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}