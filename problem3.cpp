#include<iostream>
using namespace std;
int main(){

    int row,col;
    cin>>row>>col;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<"*";
        }
        col--;
          
        cout<<endl;
    }
    cout<<"Bravo 1st problem done yourself"<<endl;











    return 0;
}