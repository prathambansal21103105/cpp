#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Please give a number"<<endl;
    cin>>n;

    int originaln=n;

    int reverse=0;

    while(n>0){
        int lastdigit;
        lastdigit=n%10;
        reverse=reverse*10+lastdigit;
        n=n/10;
    }
    cout<<originaln<<endl;
    cout<<reverse<<endl;









    return 0;
}