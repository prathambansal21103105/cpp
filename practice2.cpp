#include<iostream>
#include<math.h>
using namespace std;
int main(){

    int n;
    cout<<"Please give a number"<<endl;
    cin>>n;
    int originaln=n;

    int sum=0;

    while(n>0){
        int lastdigit;
        lastdigit=n%10;
        sum=sum+pow(lastdigit,3);
        n=n/10;
    }
    cout<<"sum of cubes of digits:"<<endl;
    cout<<sum<<endl;

    if(sum==originaln){
        cout<<"Your number is an Armstrong number"<<endl;
        }

        else{
            cout<<"Its not an Armstrong number"<<endl;
        }






    return 0;
}