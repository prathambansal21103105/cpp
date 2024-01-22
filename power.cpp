#include<iostream>
using namespace std;

int power(int b,int p){
    if(p==0){
        return 1;
    }
    int smallOutput=power(b,p-1);
    int output=b*smallOutput;
    return output;
}

int main(){
    int b;
    cin>>b;
    int p;
    cin>>p;
    cout<<power(b,p)<<endl;
    return 0;
}