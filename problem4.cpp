#include<iostream>
using namespace std;
int main(){

    int row,col;
    cin>>row>>col;

    for(int i=1;i<=row;i++){
        for(int j=1;j<col;j++){
            cout<<" ";
        }
        for(int z=1;z<=i;z++){
            cout<<"*";
        }
        col--;
        cout<<endl;
    }
    cout<<"Bravo second problem solved successfully"<<endl;








    return 0;
}