#include<iostream>
using namespace std;
int main(){
    int f;
    cout<<"Enter the value in fah:"<<endl;
    cin>>f;
    int c=(5/9)*(f-32);
    cout<<c<<endl;
    cout<<(5.0/9)*(f-32)<<endl;
    return 0;
}