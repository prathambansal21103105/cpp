#include<iostream>
using namespace std;
int add(int num1,int num2){
    int sum=num1+num2;
    cout<<"The sum is--"<<endl;
    return sum;
}
int main(){
    cout<<add(1,2)<<endl;
    return 0;
}
