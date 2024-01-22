#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Give a number"<<endl;
    cin>>n;

    int sum=1;

    for(int i=1;i<=n;i++){
        sum=sum*i;
    }
    cout<<"factorial of the number:"<<endl;
    cout<<sum<<endl;




    return 0;
}