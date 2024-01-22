#include<iostream>
using namespace std;
int main(){
    for(int i=1;i<=4;i++){
        for(int c=1;c<=(4-i);c++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"   *";
        }
        cout<<endl;
    }
}