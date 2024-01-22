#include<iostream>
using namespace std;
#include"complex.cpp"
int main(){
    int r1,i1;
    cin>>r1>>i1;
    ComplexNumbers c1(r1,i1);
    
    int r2,i2;
    cin>>r2>>i2;
    ComplexNumbers c2(r2,i2);

    int choice;
    cin>>choice;

    if(choice==1){
        c1.plus(c2);
    }
    else if(choice==2){
        c1.multiply(c2);
    }
    c1.print();

    return 0;
}