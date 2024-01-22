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
    cout<<"The reverse number:"<<endl;
    cout<<reverse<<endl;

    if(reverse==originaln){
        cout<<"Its a palindrome number"<<endl;
    }
    else{
        cout<<"Its not a plaindrome number"<<endl;
    }







    return 0;
}