#include<iostream>
using namespace std;
#include"Fraction.cpp"
int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();

    Fraction const f3; //when we create a const object we should go to the class and mark all those functions const that do no change the value of any variable 
    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
    // f3.setNumerator(10);

    return 0;
} 