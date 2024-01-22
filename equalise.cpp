#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int input[1000];
    int add=1;
    for(int i=0;i<1000;i++){
        input[i]=add;
        add=add*2;
    }
    while(t>0){
        int a,b;
        int flag=0;
        cin>>a>>b;
        int max=0;
        int min=0;
        if(a>=b){
            max=a;
            min=b;
        }
        else{
            max=b;
            min=a;
        }
        float div1=float(max)/float(min);
        for(int i=0;i<1000;i++){
            if(input[i]==div1){
                cout<<"YES"<<endl;
                flag+=1;
                break;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        
        t-=1;
    }
    return 0;
} 