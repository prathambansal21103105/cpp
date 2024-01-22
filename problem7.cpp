#include<iostream>
using namespace std;
int main(){

    int row;
    cin>>row;

    for(int i=1;i<=4;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int k=1;k<=4-i;k++){
            cout<<"  ";
        }
         for(int k=1;k<=4-i;k++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=row;i>=row-3;i--){
        for(int l=i-4;l>=1;l--){
            cout<<"* ";
        }
        for(int m=8-i;m>=1;m--){
            cout<<"  ";
        }
        for(int m=8-i;m>=1;m--){
            cout<<"  ";
        }
        for(int l=i-4;l>=1;l--){
            cout<<"* ";
        }

        cout<<endl;

    }


     






    return 0;
}