#include<iostream>
using namespace std;
int main(){

    int n;
    
    cout<<"give a number"<<endl;
    cin>>n;

    

    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=9;j++){
            int sum=i+j;
            if(sum%4==0){
                cout<<"* ";
            }
            
            else if(i==2){
                if(j%4==0){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
            else{
                cout<<"  ";
            }
        }
        
        cout<<endl; 

    }





    return 0;
}