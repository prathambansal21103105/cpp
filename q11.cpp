#include<iostream>
using namespace std;
int main(){
    char input1;
    char input2;
    cin>>input1>>input2;
    int n1=input1-48;
    int n2=input2-48;
    int n3=n1*10+n2;
    int n4=n3+96;
    char a=n4;
    cout<<a<<endl;
    return 0;
}