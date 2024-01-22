#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Input a number:";
    cin>>n;
       
    int reverse=0;
    if(n==0){
        cout<<"zero"<<endl;
    }        
        while(n>0){       
            int lastdigit=n%10;
            reverse=lastdigit;
            switch(reverse){
                case 1:
                cout<<"one ";
                break;
                case 2:
                cout<<"two ";
                break;
                case 3:
                cout<<"three ";
                break;
                case 4:
                cout<<"four ";
                break;    
                case 5:
                cout<<"five ";
                break;
                case 6:
                cout<<"six ";
                break;
                case 7:
                cout<<"seven ";
                break;
                case 8:
                cout<<"eight ";
                break;
                case 9:
                cout<<"nine ";
                break;   
                default:
                cout<<"wrong input ";
                break;   
            }
            n=int(n/10); 
        }
    cout<<endl;    
    return 0;
}