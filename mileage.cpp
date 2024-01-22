#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        double input[5];
        for(int i=0;i<5;i++){
            cin>>input[i];
        }
        double n=input[0];
        double x=input[1];
        double y=input[2];
        double a=input[3];
        double b=input[4];
        double petrol_cost=(n/a)*x;
        double diesel_cost=(n/b)*y;
        if (petrol_cost<diesel_cost){
            cout<<"PETROL"<<endl;
        }
        else if(diesel_cost<petrol_cost){
            cout<<"DIESEL"<<endl;
        }
        else{
            cout<<"ANY"<<endl;
        }
        t-=1;
    }
    return 0;
}