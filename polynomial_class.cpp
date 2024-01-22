#include<iostream>
using namespace std;
class Polynomial{
    int *degCoeff;
    int size;
    int max1;
    public:
    Polynomial(){
        degCoeff=new int[1000];
        for(int i=0;i<1000;i++){
            degCoeff[i]=0;
        }
        size=0;
        max1=0;
    }
    Polynomial(Polynomial const &p){
        this -> degCoeff=new int[p.size];
        this -> size=p.size;
        this -> max1=p.max1;
        for(int i=0;i<size;i++){
            degCoeff[i]=p.degCoeff[i];
        }
    }
    void setCoefficient(int deg,int coeff){
        this -> degCoeff[deg]=coeff;
        if(deg>=max1){
            max1=deg+1;
        }
        this -> size=max1;
    }
    Polynomial operator+(Polynomial const &p){
        int* sum=new int[max(this->size,p.size)];
        for(int i=0;i<max(this->size,p.size);i++){
            sum[i]=this->degCoeff[i]+p.degCoeff[i];
        }
        Polynomial final;
        final.degCoeff=sum;
        final.size=max(this->size,p.size);
        final.max1=max(this->size,p.size);
        return final;
    }
    Polynomial operator-(Polynomial const &p){
        int* sum=new int[max(this->size,p.size)];
        for(int i=0;i<max(this->size,p.size);i++){
            sum[i]=this->degCoeff[i]-p.degCoeff[i];
        }
        Polynomial final;
        final.degCoeff=sum;
        final.size=max(this->size,p.size);
        final.max1=max(this->size,p.size);
        return final;
    }
    Polynomial operator*(Polynomial const &p){
        int* sum=new int[this->size+p.size];
        for(int i=0;i<this->size+p.size;i++){
            sum[i]=0;
        }
        Polynomial final;
        for(int i=0;i<size;i++){
            int a=degCoeff[i];
            for(int j=0;j<p.size;j++){
                int b=p.degCoeff[j];
                int index=i+j;
                int coeff=a*b;
                sum[index]+=coeff;
            }
        }
        final.degCoeff=sum;
        final.size=this->size+p.size-1;
        final.max1=this->size+p.size-1;
        return final;
    }
    void operator=(Polynomial const &p){
        this -> degCoeff=new int[p.size];
        this -> size=p.size;
        this -> max1=p.max1;
        for(int i=0;i<size;i++){
            degCoeff[i]=p.degCoeff[i];
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            if(degCoeff[i]!=0){
            cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
};
int main(){
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}